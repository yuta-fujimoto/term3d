/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:17:59 by fyuta             #+#    #+#             */
/*   Updated: 2022/02/23 16:58:13 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "error.h"

void	exec_key_action(char key, t_object *object)
{
	if (key == 'q')
		rotate_y(object, true);
	else if (key == 'f')
		rotate_x(object, false);
	else if (key == 'r')
		rotate_x(object, true);
	else if (key == 'e')
		rotate_y(object, false);
	else if (key == 'd')
		translate_x(object, true);
	else if (key == 'a')
		translate_x(object, false);
	else if (key == 'w')
		translate_y(object, true);
	else if (key == 's')
		translate_y(object, false);
	else if (key == '+')
		object->camera.z += TRANSLATION_STEP;
	else if (key == '-')
		object->camera.z -= TRANSLATION_STEP;
	else if (key == '0')
		object->camera = (t_point){.z = VEIW_POINT};
	else if (key == 'x')
		exit(EXIT_SUCCESS);
}

bool	kbhit(void)
{
	struct termios	oldt;
	struct termios	newt;
	int				ch;
	int				oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = if_err(fcntl(STDIN_FILENO, F_GETFL, 0), "fcntl");
	if_err(fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK), "fcntl");
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	if_err(fcntl(STDIN_FILENO, F_SETFL, oldf), "fcntl");
	if (ch != EOF)
	{
		if_err(ungetc(ch, stdin), "ungetc");
		return (true);
	}
	return (false);
}
