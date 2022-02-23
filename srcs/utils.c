/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:02:21 by ywake             #+#    #+#             */
/*   Updated: 2022/02/23 13:35:18 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_range(int min, int value, int max)
{
	if (min >= value)
		return (false);
	if (max < value)
		return (false);
	return (true);
}
