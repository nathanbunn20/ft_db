/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 21:11:56 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/12 19:13:18 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_cpy;
	const char	*src_cpy;

	dest_cpy = dest;
	src_cpy = src;
	if (src_cpy < dest_cpy && dest_cpy < src_cpy + n)
	{
		src_cpy = src_cpy + n;
		dest_cpy = dest_cpy + n;
		while (n > 0)
		{
			*--dest_cpy = *--src_cpy;
			n--;
		}
	}
	else
		while (n > 0)
		{
			*dest_cpy++ = *src_cpy++;
			n--;
		}
	return (dest);
}
