/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <nbunn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:34:12 by nbunn             #+#    #+#             */
/*   Updated: 2017/05/05 23:07:26 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>

typedef unsigned int	t_dbid;

typedef struct			s_field
{
	char	*name;
	char	*type;
}						t_field;

typedef struct			s_entry
{
	void			**data;
	struct s_entry	*next;
}						t_entry;

typedef struct			s_table
{
	char			*name;
	t_field			*fields;
	t_entry			*first;
	struct s_table	*next;
}						t_table;

typedef struct			s_db
{
	t_dbid	id;
	char	*name;
	t_table	*tbls;
}						t_db;

char					**get_input(void);
int						error_code(int code);
char					*call_commands(char **input, int *exit,
		char *db_directory);
void					db_call_select(char **input, char *db_directory);
void					db_call_update(char **input, char *db_directory);
void					db_call_delete(char **input, char *db_directory);
void					db_call_insert(char **input, char *db_directory);
char					*db_call_create(char **command, char *db_directory);
t_table					db_call_create_table(char **input, char *db_directory,
		int *success, int *field_len);
int						print_databases(void);
char					*create_db(void);
int						dp_len(void);
char					*select_db(void);
char					*fselect_db(char *str);
char					*fcreate_db(char *str);
int						validate_db_exists(char *file_name);
char					*database_manager(int code, char *str);
int						validate_table(t_table table, int field_len);
void					free_double_char(char **ptr);
void					db_call_ls(char **command);
int						fprint_databases(char *str);
void					print_file(char **file);
char					**get_file(char *path);


#endif
