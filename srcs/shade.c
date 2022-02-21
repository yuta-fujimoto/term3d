/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuta <fyuta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:55:39 by ywake             #+#    #+#             */
/*   Updated: 2022/02/21 17:32:45 by fyuta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#define CHARSET_LEN (10)

void	print_with_shade(double closest, double farthest, double distance)
{
	const char	charset[CHARSET_LEN + 1] = "@$#*!=~-,.";
	double		level;
	char		c;

	if (distance <= 0.0)
	{
		printf("  ");
		return ;
	}
	level = (farthest - closest) / CHARSET_LEN;
	c = charset[(int)floor((distance - closest) / level)];
	printf("%c%c", c, c);
}