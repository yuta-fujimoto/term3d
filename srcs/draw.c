/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuta <fyuta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:31:20 by ywake             #+#    #+#             */
/*   Updated: 2022/02/22 16:19:34 by fyuta            ###   ########.fr       */
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

t_point	move_point_by_camera(t_point *point, t_camera *camera)
{
	t_point	moved_point;

	moved_point = *point;
	rotate_point(&moved_point, camera);
	translate_point(&moved_point, camera);
	return (moved_point);
}

// 透視投影
void	project_points(t_screen screen, t_object *object)
{
	int		sx;
	int		sy;
	t_list	*current;
	t_point	point;

	current = object->points;
	object->closest = 0.0;
	object->farthest = 0.0;
	while (current)
	{
		point = move_point_by_camera(current->content, &object->camera);
		sx = round(point.x * EXP_RATE / point.z + TERM_SIZE_X / 2.0);
		sy = round(TERM_SIZE_Y / 2.0 - point.y * EXP_RATE / (2.0 * point.z));
		current = current->next;
		if (point.z > object->farthest || object->farthest == 0.0)
			object->farthest = point.z;
		if (point.z < object->closest || object->closest == 0.0)
			object->closest = point.z;
		if (sx >= TERM_SIZE_X || sx < 0 || sy >= TERM_SIZE_Y || sy < 0)
			continue ;
		if (screen[sx][sy] > point.z || screen[sx][sy] == 0.0)
			screen[sx][sy] = point.z;
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
	static bool	init = true;

	init_screen(screen);
	project_points(screen, object);
	if (!init)
		printf("\033[%dA", TERM_SIZE_Y);
	init = false;
	print_screen(screen, object);
}
