/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:55:39 by ywake             #+#    #+#             */
/*   Updated: 2022/02/21 15:47:32 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

int	clamp(int value, int min, int max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	return (value);
}

	// const char	charset[14] = " $#*!=~-,.";
#define CHARSET_LEN (12)
void	print_with_shade(double closest, double farthest, double distance)
{
	const char	charset[CHARSET_LEN + 1] = ".,-~=!*#$@";
	double		level;

	if (distance == 0.0)
	{
		printf(" ");
		return ;
	}
	level = (farthest - closest) / CHARSET_LEN;
	printf("%c", charset[(int)floor((distance - closest) / level)]);
}
