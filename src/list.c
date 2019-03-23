/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 03:40:14 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/23 15:32:39 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file		*new_file(char *path, char *name)
{
	char		*temp;
	t_file		*new;

	MEM_CHK((new = (t_file *)malloc(sizeof(t_file))));
	new->path = ft_strdup(path);
	new->name = ft_strdup(name);
	if (path[ft_strlen(path) - 1] != '/')
	{
		temp = ft_strjoin(path, "/");
		new->full_path = ft_strjoin(temp, name);
		free(temp);
	}
	else
		new->full_path = (ft_strjoin(path, name));
	new->next = NULL;
	return (new);
}

void		add_file(t_file **head, t_file *file)
{
	file->next = *head;
	*head = file;
}
