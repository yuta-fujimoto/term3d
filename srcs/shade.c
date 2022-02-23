/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:55:39 by ywake             #+#    #+#             */
/*   Updated: 2022/02/23 15:48:23 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
// #define CHARSET ("oi!*=;:~-,.")
// #define CHARSET ("$o*=+-;:,.")
#define CHARSET ("@#0%%8$G4XBH?Ikt/!w*xoc+;\":-,.")

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
