/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:47:51 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/09 14:59:49 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#define MAX -2147483648

static size_t	get_len(int n)
{
	int		tempn;
	size_t	len;

	tempn = n;
	if (n == 0)
		len = 1;
	else
		len = 0;
	while (tempn)
	{
		tempn = tempn / 10;
		len++;
	}
	return (len);
}

static void		is_negative(int *n, size_t *len, int *sign)
{
	*sign = 1;
	*len = *len + 1;
	*n = *n * -1;
}

char			*ft_itoa(int n)
{
	int		sign;
	size_t	len;
	char	*ret;

	sign = 0;
	len = get_len(n);
	if (n < 0)
		is_negative(&n, &len, &sign);
	if (n == MAX)
		return (ft_strdup("-2147483648"));
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len--] = '\0';
	if (n == 0)
		ret[len] = '0';
	while (n)
	{
		ret[len--] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign == 1)
		ret[len] = '-';
	return (ret);
}
