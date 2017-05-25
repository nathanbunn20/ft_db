/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:02:27 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/16 20:53:14 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	len2;

	if (*to_find == '\0')
		return ((char*)str);
	len2 = ft_strlen(to_find);
	while (*str != '\0' && len >= len2)
	{
		if (*str == *to_find && ft_memcmp(str, to_find, len2) == 0)
			return ((char*)str);
		str++;
		len--;
	}
	return (NULL);
}
