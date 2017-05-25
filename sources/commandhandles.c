/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandhandles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <nbunn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 11:27:38 by nbunn             #+#    #+#             */
/*   Updated: 2017/04/26 11:29:07 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

char	**get_input(void)
{
	char	*line;
	char	**input;

	get_next_line(0, &line);
	if ((ft_strlen(line)) < 1)
		return (NULL);
	input = ft_strsplit(line, ' ');
	ft_strdel(&line);
	return (input);
}

char	*call_commands(char **input, int *exit, char *db_directory)
{
	int error;
	int	i;

	i = 0;
	error = 0;
	while (input[i])
		ft_strupcase(input[i++]);
	i = 0;
	if ((ft_strcmp(input[0], "EXIT")) == 0)
		*exit = 1;
	else if ((ft_strcmp(input[0], "SELECT")) == 0)
		db_call_select(input, db_directory);
	else if ((ft_strcmp(input[0], "UPDATE")) == 0)
		db_call_update(input, db_directory);
	else if ((ft_strcmp(input[0], "DELETE")) == 0)
		db_call_delete(input, db_directory);
	else if ((ft_strcmp(input[0], "INSERT")) == 0)
		db_call_insert(input, db_directory);
	else if ((ft_strcmp(input[0], "CREATE")) == 0)
		db_directory = db_call_create(input, db_directory);
	else if ((ft_strcmp(input[0], "LS")) == 0)
		db_call_ls(input);
	else if ((ft_strcmp(input[0], "USE")) == 0)
		db_directory = database_manager(2, input[1]);
	else if ((ft_strcmp(input[0], "PWD")) == 0)
	{
		ft_putstr(db_directory);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("Unrecognized commands\n");
		ft_putstr("Available commands:\nEXIT SELECT UPDATE\nDELETE INSERT CREATE\nLS USE PWD EXIT\n");
	}
	return (db_directory);
}