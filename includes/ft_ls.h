/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 02:35:34 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/25 16:56:43 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
**  INCLUDES
*/

# include "../libft/includes/libft.h"
# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <limits.h>

/*
**	MACROS
*/

# define FLAG_ERROR 1
# define IS_FLAG(a) ((ft_strchr("alrtRfgd", a) != NULL) ? 1 : 0)

/*
**	STRUCTS
*/

typedef	struct			s_file
{
	char				*path;
	char				*name;
	char				*full_path;
	struct s_file		*next;
}						t_file;

typedef struct			s_lsflags
{
	int					a;
	int					l;
	int					r;
	int					t;
	int					u;
	int					f;
	int					g;
	int					d;
	int					r_r;
	int					param_blocks;
}						t_lsflags;

/*
**  PROTOTYPES
*/

/*
**	ERROR
*/

void					ls_error(char *illegal_token, int error);

/*
**	FLAGS
*/

t_lsflags				*get_ls_flags(int argc, char *argv[]);

/*
**	SORT
*/

/*
**	DIR
*/

void					print_file(char *full_path,
char *name, struct stat info, t_lsflags *flags);
void					print_dir(char *path, t_lsflags *flags, int multiple);
t_file					*get_dir(char *path, t_lsflags *flags);

/*
**	DISPLAY
*/

void					print_l(struct stat info, char *path, t_lsflags *flags);
void					print_l_link(char *path);
void					get_widths(int *widths, t_file *head);

/*
**	LISTS
*/

t_file					*new_file(char *path, char *name);
void					add_file(t_file **head, t_file *file);

void					sort_list(t_file **head, t_lsflags *flags);
void					bsort_args(int argc, char *argv[], t_lsflags *flags);
void					t_bsort_args(t_list *head, t_lsflags *flags);

#endif
