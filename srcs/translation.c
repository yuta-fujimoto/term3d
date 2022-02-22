/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuta <fyuta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:17:47 by fyuta             #+#    #+#             */
/*   Updated: 2022/02/22 16:34:09 by fyuta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	translate_x(t_object *object, bool isplus)
{
	double	step;

	if (isplus)
		step = TRANSLATION_STEP;
	else
		step = -TRANSLATION_STEP;
	object->camera.pos.x -= step;
}

void	translate_y(t_object *object, bool isplus)
{
	double	step;

	if (isplus)
		step = TRANSLATION_STEP;
	else
		step = -TRANSLATION_STEP;
	object->camera.pos.y -= step;
}

void	translate_point(t_point *point, t_camera *camera)
{
	point->x -= camera->pos.x;
	point->y -= camera->pos.y;
	point->z -= camera->pos.z;
}
