/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:21:16 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/03 16:24:01 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_toupper(int c)
{
	int a;

	a = c;
	if (a >= 97 && a <= 122)
		return (a - 32);
	else
		return (c);
}
