/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:45:32 by ywake             #+#    #+#             */
/*   Updated: 2022/02/20 15:47:44 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	pexit(char *msg, int status);
void	*if_null(void *ptr, char *msg);
int		if_err(int status, char *msg);

#endif
