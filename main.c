#include "term3d.h"

// 0 ~ TERM_SIZEの範囲に切り詰め
int clamp(int v)
{
	if (v >= TERM_SIZE)
		return (TERM_SIZE - 1);
	if (v < 0)
		return (0);
	return (v);
}

// 透視投影
void project_points(double screen[TERM_SIZE][TERM_SIZE], const t_point buffer[BUFFER_SIZE], int size)
{
	int		i;
	int		x;
	int		y;
	double	z;

	i = -1;
	while (++i < size) {
		z = (buffer[i].z - VEIW_POINT) / EXP_RATE;
		x = clamp(round(buffer[i].x / z + (TERM_SIZE + 2.0) / 2.0));
		y = clamp(round(buffer[i].y / z + (TERM_SIZE + 2.0) / 2.0));
		if (screen[x][y] > z * EXP_RATE || screen[x][y] == 0.0)
			screen[x][y] = z * EXP_RATE;
	}
}

void print_screen(double screen[TERM_SIZE][TERM_SIZE])
{
	int	x;
	int	y;

	y = -1;
	while (++y < TERM_SIZE) {
		x = -1;
		while (++x < TERM_SIZE) {
			if (screen[x][y] > 0.0)
				printf(". ");
			else
				printf("  ");
		}
		printf("\n");
	}
}

void init_screen(double screen[TERM_SIZE][TERM_SIZE])
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

int main(int ac, char** av)
{
	FILE*	fp;
	t_point	p;
	t_point	buffer[BUFFER_SIZE];
	int		size;
	double	screen[TERM_SIZE][TERM_SIZE];

	(void)ac;
	size = 0;
	fp = fopen(av[1], "r");
	while (fscanf(fp, "%lf,%lf,%lf", &p.x, &p.y, &p.z) != EOF)
		buffer[size++] = p;
	fclose(fp);
	init_screen(screen);
	project_points(screen, buffer, size);
	print_screen(screen);
	while (1) {
		if (kbhit())
			exec_key_action(getchar(), buffer, screen, size);
	}
}
