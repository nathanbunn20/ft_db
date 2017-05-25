/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filehandles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 21:57:20 by nbunn             #+#    #+#             */
/*   Updated: 2017/05/05 22:03:33 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

int		dp_len(void)
{
	DIR				*dp;
	struct dirent	*ep;
	int				counter;

	counter = 0;
	dp = opendir("./databases/");
	if (dp != NULL)
	{
		while ((ep = readdir(dp)))
		{
			if ((ft_strcmp(ep->d_name, "..")) != 0)
				if ((ft_strcmp(ep->d_name, ".")) != 0)
					counter++;
		}
		(void)closedir(dp);
	}
	else
		return (-1);
	return (counter);
}

int		fprint_databases(char *str)
{
	DIR				*dp;
	struct dirent	*ep;

	dp = opendir(str);
	if (dp != NULL)
	{
		while ((ep = readdir(dp)))
		{
			if ((ft_strcmp(ep->d_name, "..")) != 0)
				if ((ft_strcmp(ep->d_name, ".")) != 0)
				{
					ft_putstr(ep->d_name);
					ft_putchar('	');
				}
		}
		(void)closedir(dp);
		ft_putchar('\n');
	}
	else
		return (-1);
	return (0);
}

int		print_databases(void)
{
	DIR				*dp;
	struct dirent	*ep;

	dp = opendir("./databases/");
	if (dp != NULL)
	{
		if (dp_len() == 0)
			return (1);
		while ((ep = readdir(dp)))
		{
			if (ft_strcmp(ep->d_name, ".") && ft_strcmp(ep->d_name, "..") &&
					ft_strcmp(ep->d_name, ".DS_Store") &&
					ft_strcmp(ep->d_name, "._.DS_Store"))
			{
				ft_putstr(ep->d_name);
				ft_putchar('	');
			}
		}
		(void)closedir(dp);
		ft_putchar('\n');
	}
	else
		return (-1);
	return (0);
}

void	free_double_char(char **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = NULL;
			i++;
		}
	}
}

void	print_file(char **file)
{
	int index;

	index = 0;
	while (file[index])
	{
		ft_putstr(file[index]);
		ft_putchar('\n');
		index++;
	}
}

char	**get_file(char *path)
{
	int		fd;
	int		ret;
	int		i;
	char	**file;

	i = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		error_code(14);
		return (NULL);
	}
	file = (char**)malloc(sizeof(char*) * 1025);
	while (1)
	{
		if ((ret = get_next_line(fd, &file[i])) <= 0)
			break ;
		i++;
	}
	if (ret == -1)
	{
		free(file);
		close(fd);
		error_code(10);
		return (NULL);
	}
	file[i] = 0;
	close(fd);
	return (file);
}
