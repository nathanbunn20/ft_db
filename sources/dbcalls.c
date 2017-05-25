/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbcalls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <nbunn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:35:22 by nbunn             #+#    #+#             */
/*   Updated: 2017/05/05 21:47:22 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

static int	valid_num_fields(char **command, int fields, int fd)
{
	int	i;

	i = 0;
	while (command[i + 2])
		i++;
	if (i != fields)
	{
		ft_putstr("Wrong number of fields. Expected ");
		ft_putnbr(fields);
		ft_putstr(".\n");
		close(fd);
		return (0);
	}
	return (1);
}

static int	get_num_fields(char *line)
{
	char	*delim;
	int		fields;

	delim = line;
	fields = 0;
	while ((delim = ft_strchr(delim + 1, ' ')))
		fields++;
	return (fields);
}

static int	open_table(char *db_directory, char *table_name)
{
	char	*dir;
	char	*path;
	int		fd;

	dir = ft_strjoin(db_directory, "/");
	path = ft_strjoin(dir, table_name);
	if ((fd = open(path, O_RDWR | O_APPEND)) == -1)
	{
		perror(path);
		close(fd);
		ft_strdel(&dir);
		ft_strdel(&path);
		return (-1);
	}
	ft_strdel(&dir);
	ft_strdel(&path);
	return (fd);
}

void		db_call_insert(char **command, char *db_directory)
{
	int		fd;
	int		fields;
	char	*line;
	int		i;

	if (!command[1])
		return ((void)error_code(8));
	ft_strlowcase(command[1]);
	if ((fd = open_table(db_directory, command[1])) == -1)
		return ((void)error_code(14));
	get_next_line(fd, &line);
	fields = get_num_fields(line);
	ft_strdel(&line);
	if (!valid_num_fields(command, fields, fd))
		return ;
	i = 1;
	while (command[++i])
	{
		ft_strlowcase(command[i]);
		write(fd, command[i], ft_strlen(command[i]));
		write(fd, " ", 1);
	}
	write(fd, "\n", 1);
	close(fd);
}
