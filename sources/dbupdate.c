/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbupdate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 20:41:17 by nbunn             #+#    #+#             */
/*   Updated: 2017/05/05 20:42:03 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

static char	**copy_replace_string(char **line, int found, char *new_string)
{
	char	**new_line;
	int		index;
	int		i;

	i = 0;
	index = 0;
	ft_strlowcase(new_string);
	while (line[index])
		index++;
	new_line = (char**)malloc(sizeof(char*) * index + 1);
	index = 0;
	while (line[index])
	{
		if (index == found)
			new_line[i] = ft_strdup(new_string);
		else
			new_line[i] = ft_strdup(line[index]);
		i++;
		index++;
	}
	new_line[i] = 0;
	return(new_line);
}

static char	*convert_to_string(char **line)
{
	//size_t	len;
	int		index;
	char	*str;
	int		line_index;
	int		str_index;

	//len = 0;
	index = 0;
	//while (line[index])
	//	len += ft_strlen(line[index++] + 1); // + 1 for space
	//len = len - 1;
	str = ft_strnew(100000000);
	index = 0;
	str_index = 0;
	while (line[index])
	{
		line_index = 0;
		while (line[index][line_index] != '\0')
		{
			str[str_index] = line[index][line_index];
			str_index++;
			line_index++;
		}
		if (line[index + 1])
			str[str_index++] = ' ';
		index++;
	}
	str[str_index] = '\0';
	return (str);
}

static void	db_call_update_other(char **command, char *path)
{
	char	**first_line;
	char	**buffer;
	int		set_found;
	int		check;
	int		index;
	char	**line;
	char	**new_line;
	char	*new_str;
	char	*tmp;
	int		fd;

	index = 1;
	check = 0;
	set_found = 0;
	buffer = get_file(path);
	if (!buffer)
	{
		ft_putstr("Specify a correct table name\n");
		return ;
	}
	first_line = ft_strsplit(buffer[0], ' ');

	//////////////////////////////////////////////////////////////////////////////////////////
	//VALIDATING IF <FIELD> (command 3) AFTER WHERE STATEMENT MATCHES A <FIELD> IN THE TABLE//
	//////////////////////////////////////////////////////////////////////////////////////////
	//ALSO GETS LOCATION OF <FIELD> ASSOCIATED WITH COMMAND 3. VARIABLE IS SET_FOUND//////////
	//////////////////////////////////////////////////////////////////////////////////////////

	ft_strlowcase(command[3]);
	while (first_line[set_found])
	{
		ft_strlowcase(first_line[set_found]);
		if ((ft_strcmp(first_line[set_found], command[3])) == 0)
		{
			check = 1;
			break ;
		}
		set_found++;
	}
	if (check != 1)
	{
		error_code(26);
		return ;
	}

	///////////////////////////////////////////////////////////////////////////////////
	//SINCE WE ARE UPDATING EVERY LINE IN THE FILE WITH VALUE (COMMAND 4) AT LOCATION//
	//FIELD SET_FOUND (COMMAND 3), WE LOOP THROUGH THE FILE LINE BY LINE AND REPLACE///
	//THE VALUE AT SET_FOUND LOCATION WITH THE NEW VALUE (COMMAND 4)///////////////////
	///////////////////////////////////////////////////////////////////////////////////
	//IF THERE WAS A SUCCESSFUL UPDATE IN THE BUFFER, WE MOVE ONTO RE-WRITING THE//////
	//NEW INFORMATION INTO THE FILE////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	while (buffer[index])
	{
		line = ft_strsplit(buffer[index], ' ');
		new_line = copy_replace_string(line, set_found, command[4]);
		new_str = convert_to_string(new_line);
		tmp = buffer[index];
		buffer[index] = new_str;
		free(tmp);
		check = 1;
		index++;
		free_double_char(line);
	}
	if (check != 1)
		error_code(27);

	///////////////////////////////////////////////////////////////////////////
	//HERE WE OPEN UP THE FILE, LOOP THROUGH THE BUFFER AND WRITE TO THE FD////
	///////////////////////////////////////////////////////////////////////////

	index = 0;
	if ((fd = open(path, O_RDWR|O_TRUNC)) == -1)
	{
		error_code(14);
		free_double_char(buffer);
		return ;
	}
	while (buffer[index])
	{
		write(fd, buffer[index], ft_strlen(buffer[index]));
		write(fd, "\n", 1);
		index++;
	}
	if ((close(fd)) == -1)
		error_code(15);
	free_double_char(buffer);
}

static void	db_call_update_where(char **command, char *path)
{
	int		fd;
	char	**buffer;
	int		found;
	int		check;
	char	**first_line;
	int		index;
	char	**line;
	int		set_found;
	char	**new_line;
	char	*new_str;
	char	*tmp;

	index = 1;
	check = 0;
	found = 0;
	set_found = 0;
	buffer = get_file(path);
	if (!buffer)// check if anything was read from file
	{
		ft_putstr("Specify a correct table name\n");
		return ;
	}
	if (!command[6] || !command[7]) //check for commands after WHERE
	{
		error_code(30);
		return ;
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	//VALIDATING IF <FIELD> (command 6) AFTER WHERE STATEMENT MATCHES A <FIELD> IN THE TABLE//
	//////////////////////////////////////////////////////////////////////////////////////////
	//ALSO GETS LOCATION OF <FIELD> ASSOCIATED WITH COMMAND 6. VARIABLE IS FOUND//////////////
	//////////////////////////////////////////////////////////////////////////////////////////

	first_line = ft_strsplit(buffer[0], ' ');
	ft_strlowcase(command[6]);
	while (first_line[found])
	{
		ft_strlowcase(first_line[found]);
		if ((ft_strcmp(first_line[found], command[6])) == 0)
		{
			check = 1;
			break ;
		}
		found++;
	}
	if (check != 1)
	{
		error_code(26);
		return ;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	//VALIDATING IF <FIELD> (command 3) AFTER WHERE STATEMENT MATCHES A <FIELD> IN THE TABLE//
	//////////////////////////////////////////////////////////////////////////////////////////
	//ALSO GETS LOCATION OF <FIELD> ASSOCIATED WITH COMMAND 3. VARIABLE IS SET_FOUND//////////
	//////////////////////////////////////////////////////////////////////////////////////////

	check = 0;
	ft_strlowcase(command[3]);
	while (first_line[set_found])
	{
		ft_strlowcase(first_line[set_found]);
		if ((ft_strcmp(first_line[set_found], command[3])) == 0)
		{
			check = 1;
			break ;
		}
		set_found++;
	}
	if (check != 1)
	{
		error_code(26);
		return ;
	}

	///////////////////////////////////////////////////////////////////////////////
	//INDEX STARTS AT 1. STARTING AT THE 2ND LINE IN FILE, LOOPS THROUGH///////////
	//SEARCHING FOR MATCHING VALUES (command 7) and at location FOUND in the file//
	///////////////////////////////////////////////////////////////////////////////
	//ONCE WE FIND MATCHING VALUES, WE KNOW WHICH LINE TO MANIPULATE. WE MAKE//////
	//A COPY OF THE LINE, BUT WITH THE NEW VALUES THAT WERE REQUESTED TO UPDATE ///
	//FROM COMMANDS 4 AND 5. THEN CONVERT THE 2D ARRAY LINE TO A 1D STRING AND ////
	//ATTACH IT TO THE FILE BUFFER (2D CHAR ARRAY).////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	//IF THERE WAS A SUCCESSFUL UPDATE IN THE BUFFER, WE MOVE ONTO RE-WRITING THE//
	//NEW INFORMATION INTO THE FILE////////////////////////////////////////////////

	check = 0;
	while (buffer[index])
	{
		line = ft_strsplit(buffer[index], ' ');
		ft_strlowcase(command[7]);
		ft_strlowcase(line[found]);
		if ((ft_strcmp(line[found], command[7])) == 0)
		{
			new_line = copy_replace_string(line, set_found, command[4]);
			new_str = convert_to_string(new_line);
			tmp = buffer[index];
			buffer[index] = new_str;
			free(tmp);
			check = 1;
			free_double_char(line);
		}
		index++;
	}
	if (check != 1)
		error_code(27);

	///////////////////////////////////////////////////////////////////////////
	//HERE WE OPEN UP THE FILE, LOOP THROUGH THE BUFFER AND WRITE TO THE FD////
	///////////////////////////////////////////////////////////////////////////

	index = 0;
	if ((fd = open(path, O_RDWR|O_TRUNC)) == -1)
	{
		error_code(14);
		free_double_char(buffer);
		return ;
	}
	while (buffer[index])
	{
		write(fd, buffer[index], ft_strlen(buffer[index]));
		write(fd, "\n", 1);
		index++;
	}
	if ((close(fd)) == -1)
		error_code(15);
	free_double_char(buffer);
}

void	db_call_update(char **command, char *db_directory)
{
	char	*dir;
	char	*path;

	if (!command[1])
	{
		error_code(6);
		return ;
	}
	if (!command[2])
	{
		error_code(28);
		return ;
	}
	if (!command[3] || !command[4])
	{
		error_code(29);
		return ;
	}
	ft_strlowcase(command[1]);
	dir = ft_strjoin(db_directory, "/");
	path = ft_strjoin(dir, command[1]);
	ft_strdel(&dir);
	if (command[5])
	{
		if ((ft_strcmp(command[5], "WHERE")) == 0)
		{
			db_call_update_where(command, path);
			ft_strdel(&path);
			return ;
		}
	}
	else
		db_call_update_other(command, path);
}
