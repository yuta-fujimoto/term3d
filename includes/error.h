/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:45:32 by ywake             #+#    #+#             */
/*   Updated: 2022/02/20 15:05:44 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	pexit(char *msg, int status);
void	*catch_null(void *ptr, char *msg);
int		catch_err(int status, char *msg);

#endif
