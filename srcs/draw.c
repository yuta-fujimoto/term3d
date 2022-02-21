/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuta <fyuta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:31:20 by ywake             #+#    #+#             */
/*   Updated: 2022/02/21 14:14:39 by fyuta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

// 0 ~ TERM_SIZEの範囲に切り詰め
int	clamp(int v)
{
	if (v >= TERM_SIZE)
		return (TERM_SIZE - 1);
	if (v < 0)
		return (0);
	return (v);
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

void	draw(double screen[TERM_SIZE][TERM_SIZE],
				t_object *object, bool reflesh)
{
	init_screen(screen);
	project_points(screen, object);
	if (reflesh)
		printf("\033[%dA", TERM_SIZE);
	print_screen(screen);
}
