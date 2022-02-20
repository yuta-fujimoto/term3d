#include "term3d.h"

void	exec_key_action(char key, double screen[TERM_SIZE][TERM_SIZE], t_object *object)
{
	if (key == 'h')
		rotate_y(object, true);
	else if (key == 'k')
		rotate_x(object, true);
	else if (key == 'l')
		rotate_y(object, false);
	else if (key == 'j')
		rotate_x(object, false);
	else if (key == 'q')
		exit(EXIT_SUCCESS);
	else
		return ;
	init_screen(screen);
	project_points(screen, object);
	printf("\x1b[H");
	print_screen(screen);
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
