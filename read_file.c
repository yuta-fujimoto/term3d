#include "term3d.h"

void exit_by_error(void)
{
	perror("term3d: ");
	exit(EXIT_FAILURE);
}

bool read_line(char *fn, t_points_set *out_set)
{
	FILE			*fp;
	unsigned int	set_size;

    fp = fopen(fn, "r");
	if (!fp)
		exit_by_error();
	out_set->p = malloc(sizeof(t_point) * set_size);
	if (!out_set)
		exit_by_error();
	out_set->size = 0;
	set_size = 1;
	while (feof(fp))
	{
		if (fscanf(fp, "%lf,%lf,%lf", &out_set->p[out_set->size].x,
			&out_set->p[out_set->size].y, &out_set->p[out_set->size].z) != 3)
			{
				free(out_set);
				exit_by_error();
			}
		out_set->size++;
		if (set_size <= out_set->size)
		{
			out_set->p = realloc(out_set->p, set_size * 2);
			if (!out_set)
				exit_by_error();
			set_size *= 2;
		}
	}
}
