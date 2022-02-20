#include "term3d.h"

// y軸周り
void	rotate_y(t_object *object, bool isleft)
{
	double	x;
	double	z;
	double	angle;
	t_list	*current;
	t_point	*point;

	if (isleft)
		angle = ROTATION_ANGLE;
	else
		angle = -ROTATION_ANGLE;
	current = object->points;
	while (current)
	{
		point = (t_point *)current->content;
		x = point->x;
		z = point->z;
		point->x = x * cos(angle) + z * sin(angle);
		point->z = -x * sin(angle) + z * cos(angle);
		current = current->next;
	}
}

// x軸周り
void	rotate_x(t_object *object, bool isleft)
{
	double	y;
	double	z;
	double	angle;
	t_list	*current;
	t_point	*point;

	if (isleft)
		angle = ROTATION_ANGLE;
	else
		angle = -ROTATION_ANGLE;
	current = object->points;
	while (current)
	{
		point = (t_point *)current->content;
		y = point->y;
		z = point->z;
		point->y = y * cos(angle) - z * sin(angle);
		point->z = y * sin(angle) + z * cos(angle);
		current = current->next;
	}
}
