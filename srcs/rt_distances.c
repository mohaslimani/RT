/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_distances.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:21:51 by belhatho          #+#    #+#             */
/*   Updated: 2021/03/13 15:21:59 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int				rt_check_distance(double c[5], t_hit *rec)
{
	double		s[4];
	int			i;
	int			num;
	double		min_sol;

	min_sol = rec->closest;
	i = -1;
	if ((num = rt_solve_quartic(c, s)))
	{
		while (++i < num)
		{
			if (s[i] >= MIN && s[i] < min_sol)
				min_sol = s[i];
		}
		if (min_sol >= MIN && min_sol < rec->closest)
		{
			rec->t = min_sol;
			return (1);
		}
	}
	return (0);
}
