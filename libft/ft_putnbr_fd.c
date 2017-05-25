/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:02:39 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/05 14:16:19 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd(("-2147483648"), fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd(('-'), fd);
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar_fd((48 + n), fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(((n % 10) + 48), fd);
}
