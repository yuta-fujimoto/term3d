#include "term3d.h"
#include "error.h"

// 0 ~ TERM_SIZEの範囲に切り詰め
int	clamp(int v)
{
	if (v >= TERM_SIZE)
		return (TERM_SIZE - 1);
	if (v < 0)
		return (0);
	return (v);
}

// 透視投影
void	project_points(double screen[TERM_SIZE][TERM_SIZE], t_object *object)
{
	int		x;
	int		y;
	double	z;
	t_list	*current;
	t_point	*point;

	current = object->points;
	while (current)
	{
		point = (t_point *)current->content;
		z = (point->z - VEIW_POINT) / EXP_RATE;
		x = clamp(round(point->x / z + TERM_SIZE / 2.0));
		y = clamp(round(TERM_SIZE / 2.0 - point->y / z));
		if (screen[x][y] > z * EXP_RATE || screen[x][y] == 0.0)
			screen[x][y] = z * EXP_RATE;
		current = current->next;
	}
}

void	print_screen(double screen[TERM_SIZE][TERM_SIZE])
{
	int	x;
	int	y;

	y = -1;
	while (++y < TERM_SIZE)
	{
		x = -1;
		while (++x < TERM_SIZE)
		{
			if (screen[x][y] > 0.0)
				printf(". ");
			else
				printf("  ");
		}
		printf("\n");
	}
}

void	init_screen(double screen[TERM_SIZE][TERM_SIZE])
{
	int	x;
	int	y;

	y = -1;
	while (++y < TERM_SIZE)
	{
		x = -1;
		while (++x < TERM_SIZE)
			screen[x][y] = 0.0;
	}
}

void	arg_validation(int argc, char const *argv[])
{
	char	*extension;

	if (argc != 2)
		return ;
	extension = strrchr(argv[1], '.');
	if (extension != NULL && !strcmp(extension, ".3d"))
		return ;
	fprintf(stderr, "invalid arguments.\n");
	exit(EXIT_FAILURE);
}

void	read_file(char const *filename, t_object *object)
{
	FILE	*file;
	t_point	*p;

	file = if_null(fopen(filename, "r"), "fopen");
	object->size = 0;
	object->points = NULL;
	while (!feof(file))
	{
		p = (t_point *)if_null(malloc(sizeof(t_point)), "malloc");
		if (fscanf(file, "%lf,%lf,%lf\n", &p->x, &p->y, &p->z) != 3)
			exit(EXIT_FAILURE);
		ft_lstadd_back(&(object->points), if_null(ft_lstnew(p), "lstnew"));
		object->size++;
	}
	if_err(fclose(file), "fclose");
}

int	main(int ac, char const **av)
{
	t_object	object;
	double		screen[TERM_SIZE][TERM_SIZE];

	arg_validation(ac, av);
	read_file(av[1], &object);
	init_screen(screen);
	project_points(screen, &object);
	print_screen(screen);
	while (1)
	{
		if (kbhit())
			exec_key_action(getchar(), screen, &object);
	}
	ft_lstclear(&object.points, free);
}
