/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:55:39 by ywake             #+#    #+#             */
/*   Updated: 2022/02/22 11:54:17 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#define CHARSET ("@$#*!=~-,.")

void	print_with_shade(double closest, double farthest, double distance)
{
	double		level;
	char		c;

	if (distance <= 0.0)
	{
		printf("  ");
		return ;
	}
	if (farthest == closest)
		level = 1;
	else
		level = (farthest - closest) / strlen(CHARSET);
	c = CHARSET[(int)floor((distance - closest) / level)];
	printf("%c%c", c, c);
}
