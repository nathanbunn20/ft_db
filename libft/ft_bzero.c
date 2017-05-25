/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 14:43:01 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/01 14:20:32 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_bzero(void *ptr, size_t nbr)
{
	unsigned char *cpy_ptr;

	cpy_ptr = ptr;
	while (nbr)
	{
		*cpy_ptr++ = 0;
		nbr--;
	}
	return (ptr);
}
