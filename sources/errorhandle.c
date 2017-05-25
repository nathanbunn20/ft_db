/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <nbunn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 11:44:43 by nbunn             #+#    #+#             */
/*   Updated: 2017/04/25 11:37:11 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

int		error_code(int code)
{
	if (code == 1)
	{
		ft_putstr("Need command FROM when using SELECT\n");
		ft_putstr("ie: SELECT FROM 'table_name'\n");
		ft_putstr("ie: SELECT country usa FROM countries\n");
		return (-2);
	}
	else if (code == 1)
	{
		ft_putstr("Incorrect command.\nCommands: SELECT UPDATE ");
		ft_putstr("DELETE INSERT CREATE\n");
		return (-2);
	}
	else if (code == 3)
	{
		ft_putstr("Expected command after CREATE\n");
		ft_putstr("ie: DATABASE TABLE\n");
		return (-3);
	}
	else if (code == 4)
	{
		ft_putstr("Unrecognized CREATE command\n");
		ft_putstr("CREATE commands: DATABASE TABLE\n");
		return (-4);
	}
	else if (code == 5)
	{
		ft_putstr("Expected command after SELECT\n");
		return (-5);
	}
	else if (code == 6)
	{
		ft_putstr("Expected command after UPDATE\n");
		ft_putstr("Usage: UPDATE <table_name> SET <field> <value> WHERE <field> <value>\n");
		ft_putstr("!Caution: When not using WHERE, UPDATE will overwrite all field(s) with value!\n");
		return (-6);
	}
	else if (code == 7)
	{
		ft_putstr("Expected command after DELETE\nCommands: ");
		ft_putstr("TABLE DATABASE\n");
		return (-7);
	}
	else if (code == 8)
	{
		ft_putstr("Expected command after INSERT\n");
		return (-8);
	}
	else if (code == 9)
	{
		ft_putstr("Expected command after FROM\n");
		return (-9);
	}
	else if (code == 10)
	{
		ft_putstr("Table is empty\n");
		return (-10);
	}
	else if (code == 11)
	{
		ft_putstr("Failed to find the database directory\n");
		return (-11);
	}
	else if (code == 12)
	{
		ft_putstr("Failed to link a database\n");
		return (-12);
	}
	else if (code == 13)
	{
		ft_putstr("Failed to create table\n");
		return (-13);
	}
	else if (code == 14)
	{
		ft_putstr("Failed to open table\n");
		return (-14);
	}
	else if (code == 15)
	{
		ft_putstr("Failed to close table\n");
		return (-15);
	}
	else if (code == 16)
	{
		ft_putstr("Table does not exist\n");
		return (-16);
	}
	else if (code == 17)
	{
		ft_putstr("Failed to verify if table exists\n");
		return (-17);
	}
	else if (code == 18)
	{
		ft_putstr("File cannot be deleted\n");
		return (-18);
	}
	else if (code == 19)
	{
		ft_putstr("Incorrect data types\nData types include: ");
		ft_putstr("int char\n");
		return (-19);
	}
	else if (code == 20)
	{
		ft_putstr("Specify which table/database you want to delete\n");
		return (-20);
	}
	else if (code == 21)
	{
		ft_putstr("Database could not be deleted\n");
		ft_putstr("Try removing the tables prior to deleting the database\n");
		return (-21);
	}
	else if (code == 22)
	{
		ft_putstr("Could not find database\n");
		return (-22);
	}
	else if (code == 23)
	{
		ft_putstr("Error deleting a table within the database\n");
		return (-23);
	}
	else if (code == 24)
	{
		ft_putstr("Expected table name after FROM command\n");
		return (-24);
	}
	else if (code == 25)
	{
		ft_putstr("SELECT needs a CATEGORY to search in and a KEYWORD to search with\n");
		ft_putstr("ie: SELECT country germany FROM earth\n");
		ft_putstr("CATEGORY = country, KEYWORD = germany\n");
		return (-25);
	}
	else if (code == 26)
	{
		ft_putstr("Table does not have the category you are searching for\n");
		return (-26);
	}
	else if (code == 27)
	{
		ft_putstr("No matches found\n");
		return (-27);
	}
	else if (code == 28)
	{
		ft_putstr("Expected SET after UPDATE <table_name>\n");
		ft_putstr("Usage: UPDATE <table_name> SET <field> <value> WHERE <field> <value>\n");
		ft_putstr("!Caution: When not using WHERE, UPDATE will overwrite all field(s) with value!\n");
		return (-28);
	}
	else if (code == 29)
	{
		ft_putstr("Expected <field> and <value> after SET\n");
		ft_putstr("Usage: UPDATE <table_name> SET <field> <value> WHERE <field> <value>\n");
		ft_putstr("!Caution: When not using WHERE, UPDATE will overwrite all field(s) with value!\n");
		return (-29);
	}
	else if (code == 30)
	{
		ft_putstr("Expected <field> and <value> after WHERE\n");
		ft_putstr("Usage: UPDATE <table_name> SET <field> <value> WHERE <field> <value>\n");
		ft_putstr("!Caution: When not using WHERE, UPDATE will overwrite all field(s) with value!\n");
		return (-30);
	}
	return (0);
}