/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:03:02 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/17 17:36:22 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_file	*create_new_file(char *path)
{
	t_file		*new;

	MEM_CHK((new = (t_file *)malloc(sizeof(t_file))));
	MEM_CHK((new->f_info = (struct stat *)malloc(sizeof(struct stat))));
	new->path = path;
	stat(new->path, new->f_info);
	new->next = NULL;
	return (new);
}

void			add_new_file(t_file **head, char *path)
{
	t_file		*new;

	new = create_new_file(path);
	new->next = *head;
	*head = new;
}

t_file			*init_file_list(int ac, char **names, int start)
{
	int			i;
	t_file		*head;

	i = ac - 1;
	head = NULL;
	if (ac - 1 == start)
		add_new_file(&head, ".");
	else
	{
		while (i > start)
		{
			add_new_file(&head, names[i]);
			i--;
		}
	}
	return (head);
}
