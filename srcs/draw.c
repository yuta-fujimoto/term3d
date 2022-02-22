/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:31:20 by ywake             #+#    #+#             */
/*   Updated: 2022/02/22 12:56:14 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	init_screen(t_screen screen)
{
	int	x;
	int	y;

	y = -1;
	while (++y < TERM_SIZE_Y)
	{
		x = -1;
		while (++x < TERM_SIZE_X)
			screen[x][y] = 0.0;
	}
}

// 透視投影
void	project_points(t_screen screen, t_object *object)
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
		x = round(point->x / z + TERM_SIZE_X / 2.0) - object->camera.x;
		y = round(TERM_SIZE_Y / 2.0 - point->y / z / 2) - object->camera.y;
		current = current->next;
		if (z * EXP_RATE > object->farthest || object->farthest == 0.0)
			object->farthest = z * EXP_RATE;
		if (z * EXP_RATE < object->closest || object->closest == 0.0)
			object->closest = z * EXP_RATE;
		if (x >= TERM_SIZE_X || x < 0 || y >= TERM_SIZE_Y || y < 0)
			continue ;
		if (screen[x][y] > z * EXP_RATE || screen[x][y] == 0.0)
			screen[x][y] = z * EXP_RATE;
	}
}

void	print_screen(t_screen screen, t_object *object)
{
	int		x;
	int		y;
	char	line[TERM_SIZE_X + 1];

	line[TERM_SIZE_X] = '\0';
	y = -1;
	while (++y < TERM_SIZE_Y)
	{
		x = -1;
		while (++x < TERM_SIZE_X)
			line[x] = shader(object->closest, object->farthest, screen[x][y]);
		printf("%s\n", line);
	}
}

void	draw(t_screen screen, t_object *object)
{
	init_screen(screen);
	project_points(screen, object);
	print_screen(screen, object);
}
