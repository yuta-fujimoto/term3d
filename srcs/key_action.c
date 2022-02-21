/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuta <fyuta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:17:59 by fyuta             #+#    #+#             */
/*   Updated: 2022/02/21 17:39:12 by fyuta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	exec_key_action(char key, double screen[TERM_SIZE][TERM_SIZE],
			t_object *object)
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
	else if (key == '\e')
		exit(EXIT_SUCCESS);
	draw(screen, object, true);
}

// https://www.lisz-works.com/entry/c-lang-key-interrupt のコピペ
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
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return (true);
	}
	return (false);
}
