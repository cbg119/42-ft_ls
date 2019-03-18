/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:37:14 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/17 21:27:29 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
**  INCLUDES
*/

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <pwd.h>

/*
**  **********
*/

/*
**	MACROS
*/

# define FILE_COUNT 

/*
**************
*/

/*
**	ERRORS
*/

# define USAGE 1
# define NON_EXISTANT 2
# define C_CYAN "\x1b[36;1m"
# define C_RESET  "\x1b[0m"

/*
**	**********
*/

/*
**	STRUCTS
*/

typedef	struct			s_file
{
	char				*path;
	struct dirent		*f_entry;
	struct stat			*f_info;
	struct passwd		*o_uid;
	struct s_file		*sub_dir;
	struct s_file		*next;
}						t_file;

typedef struct			s_lsflags
{
	int		a;
	int		l;
	int		r;
	int		t;
	int		r_r;
	int		param_blocks;
}						t_lsflags;

/*
**	**********
*/

/*
**  PROTOTYPES
*/

void					error(char *illegal_token, int error, int entries);

void					handle_file(char *path);

void					ft_ls(char *path, t_lsflags *flags, int argc);

void					del_files(t_file **head);
void					add_file(t_file **head, t_file *file);
void					print_files(t_file *head, t_lsflags *flags);
void					populate_list(t_file *head, t_lsflags *flags);

t_lsflags				*get_flags(int argc, char *argv[]);

t_file					*switch_links(t_file *a, t_file *b);
t_file					*new_file(char *path);
t_file					*get_files(char *path, t_lsflags *flags);
t_file					*bubble_list(t_file *head);

void					ft_bubblestrings(char **table, int size, int start);

/*
**  **********
*/
#endif
