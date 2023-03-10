/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit_cube_troue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:35:31 by belhatho          #+#    #+#             */
/*   Updated: 2021/03/15 17:35:34 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vec		normale_cube_troue(t_vec p)
{
	t_vec	n;

	n.x = 4 * pow(p.x, 3) - 10 * p.x;
	n.y = 4 * pow(p.y, 3) - 10 * p.y;
	n.z = 4 * pow(p.z, 3) - 10 * p.z;
	return (vec_unit(n));
}

int			rt_cube_params(t_object *obj, t_ray *ray, t_hit *record)
{
	t_vec		x;
	double		c[5];

	x = vec_sub(ray->origin, obj->pos);
	c[4] = (ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x) +
		(ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y)\
			+ (ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z);
	c[3] = 4 * ((ray->dir.x * ray->dir.x * ray->dir.x) * x.x +
			(ray->dir.y * ray->dir.y * ray->dir.y) * x.y\
			+ (ray->dir.z * ray->dir.z * ray->dir.z) * x.z);
	c[2] = 6 * ((ray->dir.x * ray->dir.x) * (x.x * x.x) +
			(ray->dir.y * ray->dir.y) * (x.y * x.y)\
			+ (ray->dir.z * ray->dir.z) * (x.z * x.z)) - 5 *
		((ray->dir.x * ray->dir.x) + (ray->dir.y * ray->dir.y)\
		+ (ray->dir.z * ray->dir.z));
	c[1] = 4 * ((ray->dir.x * x.x * x.x * x.x)\
		+ (ray->dir.y * x.y * x.y * x.y) + (ray->dir.z * x.z * x.z * x.z))\
		- 10 * (ray->dir.x * x.x + ray->dir.y * x.y +
				ray->dir.z * x.z);
	c[0] = (x.x * x.x * x.x * x.x) + (x.y * x.y * x.y * x.y) +
	(x.z * x.z * x.z * x.z) - 5 * ((x.x * x.x) + (x.y * x.y) + (x.z * x.z)) +
		11.8;
	return (rt_check_distance(c, record));
}

int			rt_hit_cube_troue(t_object *obj, t_ray *ray, t_hit *record)
{
	if (rt_cube_params(obj, ray, record))
	{
		record->p = vec_ray(ray, record->t);
		record->n = normale_cube_troue(record->p);
		return (1);
	}
	return (0);
}
