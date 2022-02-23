/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuta <fyuta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:17:47 by fyuta             #+#    #+#             */
/*   Updated: 2022/02/21 14:17:50 by fyuta            ###   ########.fr       */
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
	object->camera.x -= step;
}

void	translate_y(t_object *object, bool isplus)
{
	double	step;

	if (isplus)
		step = TRANSLATION_STEP;
	else
		step = -TRANSLATION_STEP;
	object->camera.y += step;
}
