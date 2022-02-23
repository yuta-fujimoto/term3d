/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:19:47 by fyuta             #+#    #+#             */
/*   Updated: 2022/02/23 16:12:39 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	rotate_y(t_object *object, bool isleft)
{
	double	x;
	double	z;
	double	angle;
	t_list	*current;
	t_point	*point;

	if (isleft)
		angle = ROTATION_ANGLE * M_PI / 180.0;
	else
		angle = -ROTATION_ANGLE * M_PI / 180.0;
	current = object->points;
	while (current)
	{
		point = (t_point *)current->content;
		x = point->x;
		z = point->z;
		point->x = x * cos(angle) + z * sin(angle);
		point->z = -x * sin(angle) + z * cos(angle);
		current = current->next;
	}
}

void	rotate_x(t_object *object, bool isleft)
{
	double	y;
	double	z;
	double	angle;
	t_list	*current;
	t_point	*point;

	if (isleft)
		angle = ROTATION_ANGLE * M_PI / 180.0;
	else
		angle = -ROTATION_ANGLE * M_PI / 180.0;
	current = object->points;
	while (current)
	{
		point = (t_point *)current->content;
		y = point->y;
		z = point->z;
		point->y = y * cos(angle) - z * sin(angle);
		point->z = y * sin(angle) + z * cos(angle);
		current = current->next;
	}
}
