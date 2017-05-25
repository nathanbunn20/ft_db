/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesomecommands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:41:22 by nbunn             #+#    #+#             */
/*   Updated: 2017/05/04 21:41:24 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void	db_call_ls(char **command)
{
	int		index;
	char	*path;

	index = 0;
	if (!command[index + 1])
		print_databases();
	else
	{
		ft_strlowcase(command[index + 1]);
		path = ft_strjoin("./databases/", command[index + 1]);
		if ((fprint_databases(path)) == -1)
		{
			ft_putstr(command[index + 1]);
			ft_putstr(" does not exist\n");
			ft_strdel(&path);
			return ;
		}
	}
}