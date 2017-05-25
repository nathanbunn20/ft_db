/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbdelete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:24:08 by nbunn             #+#    #+#             */
/*   Updated: 2017/05/05 22:48:06 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

static void	db_call_delete_database(char **command)
{
	int				error;
	int				index;
	char			*target_directory;
	char			*target_file;
	DIR				*dp;
	struct dirent	*ep;
	char			*tmp;

	index = 0;
	ft_strlowcase(command[index + 2]);
	target_directory = ft_strjoin("./databases/", command[index + 2]);
	dp = opendir(target_directory);
	if (dp != NULL)
	{
		while ((ep = readdir(dp)))
		{
			if ((ft_strcmp(ep->d_name, "..")) != 0)
				if ((ft_strcmp(ep->d_name, ".")) != 0)
				{
					target_file = ft_strjoin(target_directory, "/");
					tmp = target_file;
					target_file = ft_strjoin(target_file, ep->d_name);
					ft_strdel(&tmp);
					if ((remove(target_file)) == -1)
					{
						ft_strdel(&target_file);
						ft_strdel(&target_directory);
						error = error_code(23);
						return ;
					}
					ft_strdel(&target_file);
				}
		}
		(void)closedir(dp);
	}
	else
	{
		ft_strdel(&target_directory);
		error = error_code(22);
		return ;
	}
	if ((remove(target_directory)) == -1)
	{
		error = error_code(21);
		return ;
	}
	ft_putstr("Database ");
	ft_putstr(command[index + 2]);
	ft_putstr(" has been deleted\n");
	ft_strdel(&target_directory);
}

static void	db_call_delete_table(char **command, char *db_directory)
{
	char	*target_directory;
	char	*tmp;
	int		fd;

	target_directory = ft_strjoin(db_directory, "/");
	tmp = target_directory;
	ft_strlowcase(command[2]);
	target_directory = ft_strjoin(target_directory, command[2]);
	ft_strdel(&tmp);
	if ((fd = open(target_directory, O_RDONLY)) == -1)
		return ((void)error_code(16));
	if ((close(fd)) == -1)
		return ((void)error_code(17));
	if ((remove(target_directory)) == -1)
		return ((void)error_code(18));
	ft_putstr("Table ");
	ft_putstr(command[2]);
	ft_putstr(" has been deleted\n");
}

void	db_call_delete(char **command, char *db_directory)
{
	if (!command[1])
	{
		error_code(7);
		return ;
	}
	if (!command[2])
	{
		error_code(20);
		return ;
	}
	ft_strupcase(command[1]);
	if ((ft_strcmp(command[1], "TABLE")) == 0)
	{
		db_call_delete_table(command, db_directory);
		return ;
	}
	else if ((ft_strcmp(command[1], "DATABASE")) == 0)
	{
		db_call_delete_database(command);
		return ;
	}
}
