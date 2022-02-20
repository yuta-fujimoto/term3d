#include "term3d.h"


// y軸周り
void rotate_y(t_point buffer[BUFFER_SIZE], int size, bool isleft)
{
	int		i;
	double	x;
	double	z;
	double	angle;

	if (isleft)
		angle = ROTATION_ANGLE;
	else
		angle = -ROTATION_ANGLE;
	i = -1;
	while (++i < size) {
		x = buffer[i].x;
		z = buffer[i].z;
		buffer[i].x = x * cos(angle) + z * sin(angle);
		buffer[i].z = -x * sin(angle) + z * cos(angle);
	}
}


// x軸周り
void rotate_x(t_point buffer[BUFFER_SIZE], int size, bool isleft)
{
	int		i;
	double	y;
	double	z;
	double	angle;

	i = -1;
	if (isleft)
		angle = ROTATION_ANGLE;
	else
		angle = -ROTATION_ANGLE;
	while (++i < size) {
		y = buffer[i].y;
		z = buffer[i].z;
		buffer[i].y = y * cos(angle) - z * sin(angle);
		buffer[i].z = y * sin(angle) + z * cos(angle);
	}
}
