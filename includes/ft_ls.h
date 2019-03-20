/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:29:29 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/20 00:24:14 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>


# define C_RED "\x1b[0;31m"
# define C_CYAN "\x1b[36;1m"
# define C_RESET  "\x1b[0m"

# define IS_FLAG(a) ((ft_strchr("alrtR", a) != NULL) ? 1 : 0)

typedef struct			s_lslist
{
	void				*data;
	int					is_file;
	struct s_lslist		*next;
}						t_lslist;

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

void					free_paths(t_lslist *path);
void					ls_lstpush(t_lslist **head, t_lslist *to_add);
void					ls_lstadd(t_lslist **head, t_lslist *to_add);
void					flag_error(char illegal_flag);
void					open_error_check(char *path, int *errored);
void					isort_arguments(int argc, char *argv[], int start);

t_lslist				*ls_lstnew(void *content, int is_file);
t_lslist				*ls_lstjoin(t_lslist **file, t_lslist **dir);

t_lsflags				*get_ls_flags(int argc, char *argv[]);

t_file					*create_file_list(t_lslist *paths, t_lsflags *flags);

#endif
