/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:23:29 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/02 12:45:24 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *ret;

	ret = dest;
	while (*dest)
		dest++;
	while (n)
	{
		if (!(*dest++ = *src++))
			return (ret);
		n--;
	}
	*dest = '\0';
	return (ret);
}
