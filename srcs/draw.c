/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:31:20 by ywake             #+#    #+#             */
/*   Updated: 2022/02/21 15:48:36 by ywake            ###   ########.fr       */
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
	while (current)
	{
		point = (t_point *)current->content;
		z = (point->z - object->camera.z) / EXP_RATE;
		x = round(point->x / z + TERM_SIZE / 2.0) - object->camera.x;
		y = round(TERM_SIZE / 2.0 - point->y / z) - object->camera.y;
		current = current->next;
		if (x >= TERM_SIZE || x < 0 || y >= TERM_SIZE || y < 0)
			continue ;
		if (screen[x][y] > z * EXP_RATE || screen[x][y] == 0.0)
			screen[x][y] = z * EXP_RATE;
	}
}

void	print_screen(double screen[TERM_SIZE][TERM_SIZE])
{
	int		x;
	int		y;
	double	closest;
	double	farthest;

	closest = 0.0;
	farthest = 0.0;
	y = -1;
	while (++y < TERM_SIZE)
	{
		x = -1;
		while (++x < TERM_SIZE)
		{
			printf("%f, ", screen[x][y]);
			if (farthest < screen[x][y])
				farthest = screen[x][y];
			if (closest == 0.0 || closest > screen[x][y])
				closest = screen[x][y];
		}
	}
	y = -1;
	while (++y < TERM_SIZE / 2)
	{
		x = -1;
		while (++x < TERM_SIZE)
		{
			print_with_shade(
				closest, farthest,
				(screen[x][y * 2] + screen[x][y * 2 + 1]) / 2);
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
		printf("\033[%dA", TERM_SIZE / 2);
	print_screen(screen);
}
