/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:18:39 by fyuta             #+#    #+#             */
/*   Updated: 2022/02/21 15:41:47 by ywake            ###   ########.fr       */
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

# define TERM_SIZE 30
# define BUFFER_SIZE 1500
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif // !M_PI
# define ROTATION_ANGLE 15.0 * M_PI / 180.0
# define TRANSLATION_STEP 2.0
# define VEIW_POINT -20.0
# define EXP_RATE 100.0
# define EPSILON 1.0
typedef struct s_point {
	double	x;
	double	y;
	double	z;

}	t_point;

typedef struct s_object {
	int			size;
	t_list		*points;
	t_point		camera;

}	t_object;

void	rotate_y(t_object *object, bool isleft);
void	rotate_x(t_object *object, bool isleft);
bool	kbhit(void);
void	exec_key_action(char key, double screen[TERM_SIZE][TERM_SIZE],
			t_object *object);
void	file_to_object(char const *filename, t_object *object);
void	centerize(t_object *object);
void	draw(double screen[TERM_SIZE][TERM_SIZE],
			t_object *object, bool reflesh);
void	translate_x(t_object *object, bool isplus);
void	translate_y(t_object *object, bool isplus);
void	print_with_shade(double closest, double farthest, double distance);

#endif
