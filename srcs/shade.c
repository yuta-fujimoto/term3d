/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuta <fyuta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:55:39 by ywake             #+#    #+#             */
/*   Updated: 2022/02/22 17:34:27 by fyuta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#define CHARSET ("@$#!=*~-,.")

char	shader(double closest, double farthest, double distance)
{
	double		level;
	char		c;

	if (distance <= 0.0)
		return (' ');
	if (farthest == closest)
		level = 1;
	else
		level = (farthest - closest) / (strlen(CHARSET) - 1);
	c = CHARSET[(int)floor((distance - closest) / level)];
	return (c);
}
