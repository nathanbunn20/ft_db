/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:04:47 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/21 17:39:13 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	if (!*to_find)
		return ((char*)str);
	while (*str)
	{
		if (ft_memcmp(str, to_find, ft_strlen(to_find)) == 0)
			return ((char*)str);
		str++;
	}
	return (NULL);
}
