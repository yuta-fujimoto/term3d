/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuta <fyuta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:19:47 by fyuta             #+#    #+#             */
/*   Updated: 2022/02/22 16:31:29 by fyuta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

// y軸周り
void	rotate_y(t_object *object, bool isleft)
{
	double	angle;

	if (isleft)
		angle = ROTATION_ANGLE * M_PI / 180.0;
	else
		angle = -ROTATION_ANGLE * M_PI / 180.0;
	object->camera.angle_y += angle;
}

// x軸周り
void	rotate_x(t_object *object, bool isleft)
{
	double	angle;

	if (isleft)
		angle = ROTATION_ANGLE * M_PI / 180.0;
	else
		angle = -ROTATION_ANGLE * M_PI / 180.0;
	object->camera.angle_x += angle;
}

void	rotate_point(t_point *point, t_camera *camera)
{
	double	sine;
	double	cosine;
	t_point	temp;

	sine = sin(camera->angle_x);
	cosine = cos(camera->angle_x);
	temp = *point;
	point->y = temp.y * cosine - temp.z * sine;
	point->z = temp.y * sine + temp.z * cosine;
	sine = sin(camera->angle_y);
	cosine = cos(camera->angle_y);
	temp = *point;
	point->x = temp.x * cosine + temp.z * sine;
	point->z = -temp.x * sine + temp.z * cosine;
}
