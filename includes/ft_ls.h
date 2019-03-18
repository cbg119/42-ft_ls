/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:37:14 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/17 17:36:36 by cbagdon          ###   ########.fr       */
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

/*
**  **********
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

void			add_new_file(t_file **head, char *path);
void			display(t_file *files, t_lsflags *flags);
void	ft_bubblestrings(char **table, int size, int start);

t_lsflags		*get_lsflags(int argc, char *argv[]);

t_file			*read_dir(char *path, t_lsflags *flags);
t_file			*init_file_list(int ac, char **names, int start);

/*
**  **********
*/
#endif
