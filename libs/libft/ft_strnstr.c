/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 21:39:41 by ibel-kha          #+#    #+#             */
/*   Updated: 2019/05/27 02:07:42 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		check(const char *str, const char *to_fi, size_t j, size_t len)
{
	size_t	i;

	i = 0;
	while (*(str - i))
		i++;
	i--;
	if (i + ft_strlen(to_fi) > len + 1)
		return (0);
	while (to_fi[j] != '\0')
	{
		if (to_fi[j] != str[j])
			return (0);
		j++;
	}
	return (1);
}

char			*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(str) >= ft_strlen(to_find))
	{
		if (to_find[0] == '\0')
			return ((char*)str);
		while (str[i] != '\0' && i < len)
		{
			if (to_find[j] != str[i])
				i++;
			else if (check(&str[i], &to_find[j], j, len) != 1)
				i++;
			else
				return ((char*)str + i);
		}
	}
	return (NULL);
}
