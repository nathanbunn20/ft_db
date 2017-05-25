/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:34:08 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/16 20:21:15 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_atoi(const char *str)
{
	int x;
	int sign;
	int i;

	sign = 1;
	x = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] <= '9' && str[i] >= '0'))
		x = x * 10 + (str[i++] - 48);
	return (sign * x);
}
