/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbhandles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:41:20 by nbunn             #+#    #+#             */
/*   Updated: 2017/05/05 22:48:19 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

/*
** code numbers are as follows
** 0: run whole manager (required on boot)
** 1: run on create mode
** 2: run on select mode
*/

char	*database_manager(int code, char *str)
{
	char	*db_directory;
	int		check_new_db;

	check_new_db = 1;
	if (code == 0)
		check_new_db = print_databases();
	else if (code == 1 && !str)
		return (create_db());
	else if (code == 1 && str)
	{
		ft_putstr("Creating ");
		ft_putstr(str);
		ft_putstr(" directory\n");
		return (fcreate_db(str));
	}
	else if (code == 2 && str)
		return (fselect_db(str));
	else if (code == 2 && !str)
		return (select_db());
	if (check_new_db == 1)
		db_directory = create_db();
	else if (check_new_db == -1)
	{
		error_code(11);
		ft_putstr("Creating new directory...\n");
		if ((mkdir("./databases/", 0700)) != 0)
			return (NULL);
		db_directory = create_db();
	}
	else
		db_directory = select_db();
	return (db_directory);
}

char	*create_db(void)
{
	char	*input;
	char	*directory;

	ft_putstr("Enter new database name: ");
	get_next_line(0, &input);
	if ((ft_strlen(input)) < 1)
	{
		ft_strdel(&input);
		return (0);
	}
	ft_strlowcase(input);
	directory = ft_strjoin("databases/", input);
	ft_strupcase(input);
	if ((ft_strcmp("EXIT", input)) == 0)
		exit(0);
	if (mkdir(directory, 0700))
	{
		ft_strdel(&input);
		return (NULL);
	}
	ft_putstr("Created ");
	ft_putstr(input);
	ft_putstr(" database.\n");
	ft_strdel(&input);
	return (directory);
}

char	*fcreate_db(char *str)
{
	char	*directory;
	int		check;

	if (!str)
		return (select_db());
	ft_strlowcase(str);
	directory = ft_strjoin("databases/", str);
	ft_strupcase(str);
	if ((ft_strcmp("EXIT", str)) == 0)
		exit(0);
	check = mkdir(directory, 0700);
	if (check != 0)
		return (NULL);
	return (directory);
}

int		validate_db_exists(char *file_name)
{
	DIR				*dp;
	struct dirent	*ep;

	dp = opendir("./databases/");
	ft_strlowcase(file_name);
	if (dp != NULL)
	{
		while ((ep = readdir(dp)))
		{
			if ((ft_strcmp(ep->d_name, "..")) != 0)
				if ((ft_strcmp(ep->d_name, ".")) != 0)
				{
					if ((ft_strcmp(ep->d_name, file_name)) == 0)
						return (1);
				}
		}
		(void)closedir(dp);
	}
	else
		return (-1);
	return (0);
}

char	*select_db(void)
{
	char	*input;
	char	*directory;

	ft_putstr("Select which database to work in: ");
	get_next_line(0, &input);
	if ((ft_strlen(input)) < 1)
		return (0);
	ft_strlowcase(input);
	directory = ft_strjoin("databases/", input);
	ft_strupcase(input);
	if ((ft_strcmp("EXIT", input)) == 0)
		exit(0);
	if (validate_db_exists(input) == 1)
	{
		ft_putstr("Now working in ");
		ft_putstr(input);
		ft_putstr(" database.\n");
	}
	else
	{
		ft_strdel(&directory);
		ft_putstr("Database does not exist\nCreating new database...");
		directory = fcreate_db(input);
		if (directory)
			ft_putstr("done\n");
		else
		{
			ft_strdel(&input);
			return (NULL);
		}
	}
	ft_strdel(&input);
	return (directory);
}

char	*fselect_db(char *str)
{
	char	*directory;

	if (!str)
		return (select_db());
	ft_strlowcase(str);
	if (validate_db_exists(str) == 1)
	{
		directory = ft_strjoin("databases/", str);
		ft_putstr("Now working in ");
		ft_putstr(str);
		ft_putstr(" database.\n");
	}
	else
	{
		ft_putstr("Database does not exist\nCreating new database...");
		directory = fcreate_db(str);
		if (directory)
		{
			ft_putstr("done\n");
			ft_putstr("Now working in ");
			ft_putstr(str);
			ft_putstr(" database.\n");
		}
		else
			return (NULL);
	}
	return (directory);
}
