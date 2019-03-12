/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:37:14 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/11 18:55:11 by cbagdon          ###   ########.fr       */
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

/*
**  **********
*/

/*
**	STRUCTS
*/

typedef	struct			s_file
{
	char				*path;
	struct dirent		*f_entry;
	struct stat			*f_info;
	struct s_file		*next;
}						t_file;

/*
**	**********
*/

/*
**  PROTOTYPES
*/

t_file		*new_file(char *path);
void		del_files(t_file **head);
void		add_file(t_file **head, t_file *file);
t_file		*bubble_list(t_file *head);

/*
**  **********
*/
#endif
