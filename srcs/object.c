/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centerize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:24:30 by ywake             #+#    #+#             */
/*   Updated: 2022/02/20 18:41:25 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "error.h"

void	file_to_object(char const *filename, t_object *object)
{
	FILE	*file;
	t_point	*p;

	file = if_null(fopen(filename, "r"), "fopen");
	object->size = 0;
	object->points = NULL;
	while (!feof(file))
	{
		p = (t_point *)if_null(malloc(sizeof(t_point)), "malloc");
		if (fscanf(file, "%lf,%lf,%lf\n", &p->x, &p->y, &p->z) != 3)
			exit(EXIT_FAILURE);
		ft_lstadd_back(&(object->points), if_null(ft_lstnew(p), "lstnew"));
		object->size++;
	}
	if_err(fclose(file), "fclose");
}

t_point	get_center(t_object *object)
{
	t_point	center;
	t_list	*current;
	t_point	*point;

	center = (t_point){};
	current = object->points;
	while (current)
	{
		point = (t_point *)current->content;
		center.x += point->x;
		center.y += point->y;
		center.z += point->z;
		current = current->next;
	}
	center.x /= object->size;
	center.y /= object->size;
	center.z /= object->size;
	return (center);
}

void	centerize(t_object *object)
{
	t_point	center;
	t_list	*current;
	t_point	*point;

	center = get_center(object);
	current = object->points;
	while (current)
	{
		point = (t_point *)current->content;
		point->x -= center.x;
		point->y -= center.y;
		point->z -= center.z;
		current = current->next;
	}
}
