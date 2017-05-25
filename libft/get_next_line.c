/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <nbunn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:28:06 by nbunn             #+#    #+#             */
/*   Updated: 2017/04/24 11:55:57 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		retrieve(int const fd, char *buff, char *s[fd])
{
	char		*tmp;
	char		*p;
	int			i;

	while (!(VAL) && (i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		tmp = s[fd];
		s[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	if (i == -1)
		return (-1);
	if (i == 0 && !ft_strlen(s[fd]))
		return (0);
	return (1);
}

static int		done_reading(char **line, char **s)
{
	*line = *s;
	*s = NULL;
	return (0);
}

static void		get_line_helper(char **temp, char **s)
{
	*temp = *s;
	*s = ft_strdup(ft_strchr(*s, '\n') + 1);
	ft_strdel(temp);
}

int				get_next_line(int const fd, char **line)
{
	static char	*s[1025];
	int			i;
	char		buff[BUFF_SIZE + 1];
	char		*temp;

	temp = NULL;
	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(0);
	if ((i = retrieve(fd, buff, &*s)) == -1)
		return (-1);
	if (i == 0)
		return (done_reading(line, &s[fd]));
	if (ft_strchr(s[fd], '\n'))
		*line = ft_strsub(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd]);
	else
		*line = ft_strdup(s[fd]);
	if (ft_strchr(s[fd], '\n'))
		get_line_helper(&temp, &s[fd]);
	else
		ft_strdel(&s[fd]);
	return (1);
}
