/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:19:28 by fyuta             #+#    #+#             */
/*   Updated: 2022/02/23 16:27:00 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "error.h"

void	arg_validation(int argc, char const *argv[])
{
	char	*extension;

	if (argc != 2)
		return ;
	extension = strrchr(argv[1], '.');
	if (extension != NULL && !strcmp(extension, ".3d"))
		return ;
	fprintf(stderr, "invalid arguments.\n");
	exit(EXIT_FAILURE);
}

int	main(int ac, char const **av)
{
	t_object	object;
	t_screen	screen;

	arg_validation(ac, av);
	file_to_object(av[1], &object);
	centerize(&object);
	object.camera = (t_point){.z = VEIW_POINT};
	draw(screen, &object);
	while (1)
	{
		if (kbhit())
		{
			exec_key_action(if_err(getchar(), "getchar"), &object);
			draw(screen, &object);
		}
	}
	ft_lstclear(&object.points, free);
}
