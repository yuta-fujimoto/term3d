#ifndef TERM3D_H_
# define TERM3D_H_

#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define TERM_SIZE 30
#define BUFFER_SIZE 1500
#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif // !M_PI
#define ROTATION_ANGLE 45.0 * M_PI / 180.0
#define VEIW_POINT -50.0
#define EXP_RATE 100.0
#define EPSILON 1.0

typedef struct s_point {
    double x;
    double y;
    double z;
} t_point;

void rotate_y(t_point buffer[BUFFER_SIZE], int size, bool isleft);
void rotate_x(t_point buffer[BUFFER_SIZE], int size, bool isleft);
bool kbhit(void);
void exec_key_action(char key, t_point buffer[BUFFER_SIZE],
	double screen[TERM_SIZE][TERM_SIZE], int size);
void init_screen(double screen[TERM_SIZE][TERM_SIZE]);
void project_points(double screen[TERM_SIZE][TERM_SIZE], const t_point buffer[BUFFER_SIZE], int size);
void print_screen(double screen[TERM_SIZE][TERM_SIZE]);

#endif
