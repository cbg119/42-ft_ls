/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:46:57 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/08 16:52:16 by cbagdon          ###   ########.fr       */
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
	struct dirent		*entry;
	struct stat			*stat_info;
}						t_file;

typedef struct			s_entries
{
	t_file				*file;
	struct s_entries	*next;
}						t_entries;

void					list_add(t_entries **head, t_entries *new);
t_entries				*new_list(t_file *file);

/*
**	**********
*/

/*
**  PROTOTYPES
*/



/*
**  **********
*/
#endif
