/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuta <fyuta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:18:39 by fyuta             #+#    #+#             */
/*   Updated: 2022/02/22 16:18:04 by fyuta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM3D_H
# define TERM3D_H

# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

# define TERM_SIZE_X 60
# define TERM_SIZE_Y 30
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif // !M_PI
# define ROTATION_ANGLE 15.0
# define TRANSLATION_STEP 2.0
# define VEIW_POINT -15.0
# define EXP_RATE 100.0
# define EPSILON 1.0
typedef struct s_point {
	double	x;
	double	y;
	double	z;

}	t_point;

typedef struct s_camera {
	t_point	pos;
	double	angle_x;
	double	angle_y;

}	t_camera;

typedef struct s_object {
	int			size;
	t_list		*points;
	t_camera	camera;
	double		closest;
	double		farthest;

}	t_object;

typedef double	t_screen[TERM_SIZE_X][TERM_SIZE_Y];

void	rotate_y(t_object *object, bool isleft);
void	rotate_x(t_object *object, bool isleft);
void	rotate_point(t_point *point, t_camera *camera);
bool	kbhit(void);
void	exec_key_action(char key, t_object *object);
void	file_to_object(char const *filename, t_object *object);
void	centerize(t_object *object);
void	draw(t_screen screen, t_object *object);
void	translate_x(t_object *object, bool isplus);
void	translate_y(t_object *object, bool isplus);
void	translate_point(t_point *point, t_camera *camera);
char	shader(double closest, double farthest, double distance);

#endif
