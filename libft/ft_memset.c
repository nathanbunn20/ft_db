/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:10:30 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/01 14:21:50 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *ptr, int src, size_t nbr)
{
	unsigned char *cpy_ptr;

	cpy_ptr = ptr;
	while (nbr)
	{
		*cpy_ptr++ = (unsigned char)src;
		nbr--;
	}
	return (ptr);
}
