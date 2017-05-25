/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:11:23 by nbunn             #+#    #+#             */
/*   Updated: 2017/04/25 12:15:53 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcrt(char const *str, size_t size)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = ft_strnew(size);
	while (size > 0)
	{
		new_str[i] = str[i];
		i++;
		size--;
	}
	new_str[i] = '\0';
	return (new_str);
}
