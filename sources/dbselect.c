/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbselect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:22:50 by nbunn             #+#    #+#             */
/*   Updated: 2017/05/05 11:22:52 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

static void	db_call_special_select(char **command, char *path)
{
	char	**file;
	char	**first_line;
	int		found;
	int		check;
	char	**line;
	int		index;

	index = 1; // gonna start on 1st line later in the function
	check = 0;
	found = 0;
	if ((ft_strcmp(command[3], "FROM")) != 0)
	{
		error_code(25); // this means there aren't 2 words between SELECT and FROM
		return ;
	}
	file = get_file(path);
	first_line = ft_strsplit(file[0], ' ');
	while (first_line[found])
	{
		if ((ft_strcmp(first_line[found], command[1])) == 0)
		{
			check = 1;
			break ;
		}
		found++;
	}
	if (check != 1)
	{
		error_code(26); // couldn't find the key(word) to search with
		return ;
	}
	// found is the location where we need to search
	check = 0;
	ft_putendl(file[0]);
	while (file[index])
	{
		line = ft_strsplit(file[index], ' ');
		ft_strlowcase(command[2]);
		ft_strlowcase(line[found]);
		if ((ft_strcmp(line[found], command[2])) == 0)
		{
			check = 1;
			ft_putendl(file[index]);
		}
		free_double_char(line);
		index++;
	}
	if (check != 1)
		error_code(27); // no matches found
}


static char	*get_path(char **command, char *db_directory)
{
	char	*path;
	char	*tmp;
	int		index;

	index = 0;
	path = ft_strjoin(db_directory, "/");
	while (command[index])
	{
		if ((ft_strcmp(command[index], "FROM")) == 0)
		{
			if (command[index + 1])
			{
				ft_strlowcase(command[index + 1]);
				tmp = path;
				path = ft_strjoin(path, command[index + 1]);
				ft_strdel(&tmp);
				return (path);
			}
			else
			{
				error_code(24);
				return (NULL);
			}
		}
		index++;
	}
	error_code(1);
	return (NULL);
}

static void	db_call_select_from(char **command, char *db_directory)
{
	char	*path;
	char	**file;

	if (!command[2])
	{
		error_code(9);
		return ;
	}
	path = get_path(command, db_directory);
	if (!path)
		return ;
	file = get_file(path);
	if (!file)
		return ;
	print_file(file);
	free_double_char(file);
	free(file);
}

void	db_call_select(char **command, char *db_directory)
{
	int		index;
	int		check;
	char	*path;

	index = 0;
	check = 0;
	//if (!command[1])
	//	return ((void)error_code(5));
	while (command[index])
	{
		if ((ft_strcmp(command[index], "FROM")) == 0)
			check = 1;
		index++;
	}
	if (check != 1)
		return ((void)error_code(1));
	if ((ft_strcmp(command[1], "FROM")) == 0)
		db_call_select_from(command, db_directory); // gets table name
	else
	{
		path = get_path(command, db_directory);
		if (!path)
			return ;
		db_call_special_select(command, path);
	}
}