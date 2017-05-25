/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <nbunn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:24:46 by nbunn             #+#    #+#             */
/*   Updated: 2017/04/25 22:53:42 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

int		main(void)
{
	char	**input;
	int		exit;
	int		error;
	char	*db_directory;

	exit = 0;
	error = 0;
	if (!(db_directory = database_manager(0, NULL)))
		return (error_code(12));
	while (exit != 1)
	{
		if ((input = get_input()))
			db_directory = call_commands(input, &exit, db_directory);
		free_double_char(input);
	}
	return (0);
}