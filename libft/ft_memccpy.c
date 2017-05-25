/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:08:53 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/02 21:46:40 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_cpy;
	const char		*src_cpy;
	unsigned char	c_cpy;

	dest_cpy = (unsigned char*)dest;
	src_cpy = src;
	c_cpy = c;
	while (n)
	{
		if ((*dest_cpy++ = *src_cpy++) == c_cpy)
			return (dest_cpy);
		n--;
	}
	return (0);
}
