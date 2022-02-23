/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:31:20 by ywake             #+#    #+#             */
/*   Updated: 2022/02/23 16:12:58 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include <float.h>
#include "utils.h"

void	init_screen(t_screen screen)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			screen[x][y] = 0.0;
	}
}

void	project_points(t_screen screen, t_object *object)
{
	int		x;
	int		y;
	double	z;
	t_list	*current;
	t_point	*point;

	current = object->points;
	object->closest = DBL_MAX;
	object->farthest = -DBL_MAX;
	while (current)
	{
		point = (t_point *)current->content;
		z = (point->z - object->camera.z) / EXP_RATE;
		x = round(point->x / z + WIDTH / 2.0 - object->camera.x);
		y = round(HEIGHT / 2.0 - point->y / (2.0 * z) - object->camera.y);
		object->farthest = fmax(z * EXP_RATE, object->farthest);
		object->closest = fmin(z * EXP_RATE, object->closest);
		if (is_range(0, x, WIDTH) && is_range(0, y, HEIGHT))
			if (screen[x][y] == 0.0 || (z > 0 && screen[x][y] > z * EXP_RATE))
				screen[x][y] = z * EXP_RATE;
		current = current->next;
	}
}

void	print_screen(t_screen screen, t_object *object)
{
	int		x;
	int		y;
	char	line[WIDTH + 1];

	line[WIDTH] = '\0';
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			line[x] = shader(object->closest, object->farthest, screen[x][y]);
		printf("%s\n", line);
	}
}

void	draw(t_screen screen, t_object *object)
{
	printf("\e[2J\e[H");
	init_screen(screen);
	project_points(screen, object);
	print_screen(screen, object);
}
