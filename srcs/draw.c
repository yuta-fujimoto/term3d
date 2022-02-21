/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuta <fyuta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:31:20 by ywake             #+#    #+#             */
/*   Updated: 2022/02/21 17:04:33 by fyuta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

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

// 透視投影
void	project_points(double screen[TERM_SIZE][TERM_SIZE], t_object *object)
{
	int		x;
	int		y;
	double	z;
	t_list	*current;
	t_point	*point;

	current = object->points;
	object->closest = 0.0;
	object->farthest = 0.0;
	while (current)
	{
		point = (t_point *)current->content;
		z = (point->z - object->camera.z) / EXP_RATE;
		x = round(point->x / z + TERM_SIZE / 2.0) - object->camera.x;
		y = round(TERM_SIZE / 2.0 - point->y / z) - object->camera.y;
		current = current->next;
		if (z * EXP_RATE > object->farthest || object->farthest == 0.0)
			object->farthest = z * EXP_RATE;
		if (z * EXP_RATE < object->closest || object->closest == 0.0)
			object->closest = z * EXP_RATE;
		if (x >= TERM_SIZE || x < 0 || y >= TERM_SIZE || y < 0)
			continue ;
		if (screen[x][y] > z * EXP_RATE || screen[x][y] == 0.0)
			screen[x][y] = z * EXP_RATE;
	}
}

void	print_screen(double screen[TERM_SIZE][TERM_SIZE], t_object *object)
{
	int		x;
	int		y;

	y = -1;
	while (++y < TERM_SIZE)
	{
		x = -1;
		while (++x < TERM_SIZE)
		{
			print_with_shade(
				object->closest, object->farthest,
				screen[x][y]);
		}
		printf("\n");
	}
}

void	draw(double screen[TERM_SIZE][TERM_SIZE],
				t_object *object, bool reflesh)
{
	init_screen(screen);
	project_points(screen, object);
	if (reflesh)
		printf("\033[%dA", TERM_SIZE);
	print_screen(screen, object);
}
