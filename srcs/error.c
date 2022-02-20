/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:45:20 by ywake             #+#    #+#             */
/*   Updated: 2022/02/20 15:47:42 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	pexit(char *msg, int status)
{
	perror(msg);
	exit(status);
}

void	*if_null(void *ptr, char *msg)
{
	if (ptr == NULL)
		pexit(msg, EXIT_FAILURE);
	return (ptr);
}

int	if_err(int status, char *msg)
{
	if (status == -1)
		pexit(msg, EXIT_FAILURE);
	return (status);
}
