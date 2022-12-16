/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 07:07:50 by ibel-kha          #+#    #+#             */
/*   Updated: 2021/03/12 19:22:48 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_clamping(double value)
{
	if (value < 0.0)
		return (0.0);
	else if (value > 1.0)
		return (1.0);
	else
		return (value);
}