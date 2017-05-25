/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_db.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:49:08 by nbunn             #+#    #+#             */
/*   Updated: 2017/05/05 15:48:00 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

int		create_table_params(t_table table, char *db_directory, int field_len)
{
	char	*table_file;
	char	*tmp;
	int		fd;
	int		i;

	ft_strlowcase(table.name);
	table_file = ft_strjoin("/", table.name);
	tmp = table_file;
	table_file = ft_strjoin(db_directory, table_file);
	ft_strdel(&tmp);
	if ((fd = open(table_file, O_RDWR|O_CREAT, 0600)) == -1)
	{
		ft_strdel(&table_file);
		return (error_code(14));
	}
	i = ~0;
	while (++i < field_len)
	{
		write(fd, table.fields[i].name, ft_strlen(table.fields[i].name));
		write(fd, " ", 1);
	}
	write(fd, "\n", 1);
	if ((close(fd)) == -1)
		error_code(15);
	ft_strdel(&table_file);
	return (1);
}

t_table	db_call_create_table(char **command, char *db_directory, int *success, int *field_len)
{
	t_table	table;
	char	*type;

	table.name = ft_strdup(command[2]);
	*field_len = ~0;
	while (command[*field_len + 3])
		*field_len += 1;
	table.fields = (t_field *)malloc(sizeof(t_field) * *field_len);
	*field_len = 0;
	while (command[*field_len + 3])
	{
		if (!(type = ft_strchr(command[*field_len + 3], ':')))
		{
			*success = 0;
			ft_putstr("Usage: <fieldname>:<type>\n");
			return (table);
		}
		else 
			*type++ = '\0';
		table.fields[*field_len].name = command[*field_len + 3];
		table.fields[*field_len].type = type;
		*field_len += 1;
	}
	db_directory++;
	*success = 1;
	return (table);
}

int		validate_table(t_table table, int field_len)
{
	int	i;

	i = 0;
	while (i < field_len)
	{
		ft_strlowcase(table.fields[i].type);
		if ((ft_strcmp(table.fields[i].type, "int")) != 0)
			if ((ft_strcmp(table.fields[i].type, "char")) != 0)
				return (-1);
		i++;
	}
	return (0);
}

char	*db_call_create(char **command, char *db_directory)
{
	t_table	table;
	int		success;
	int		field_len;

	field_len = 0;
	success = 0;
	if (!command[1])
		error_code(3);
	else if ((ft_strcmp(command[1], "DATABASE")) == 0)
		if (command[2])
			db_directory = database_manager(1, command[2]);
		else
			db_directory = database_manager(1, NULL);
	else if ((ft_strcmp(command[1], "TABLE")) == 0)
	{
		if (command[2])
			table = db_call_create_table(command, db_directory, &success, &field_len);
		else
			ft_putstr("Specify a table name.\n");
		if (!success)
			error_code(13);
		else if ((validate_table(table, field_len)) == -1)
			error_code(19);
		else if ((create_table_params(table, db_directory, field_len)) == 1)
			ft_putstr("Table created\n");
	}
	else
		error_code(4);
	free(table.fields);
	return (db_directory);
}
