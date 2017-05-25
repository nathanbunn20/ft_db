/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:20 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/10 23:22:01 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) - 1;
	if (s[i + 1] == '\0' && (unsigned char)c == '\0')
		return ((char*)s + i + 1);
	while (s[i] != (char)c)
	{
		if (i < 0)
			return (0);
		i--;
	}
	return ((char*)s + i);
}
