/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 23:33:16 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/20 00:28:58 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_file	*new_file(char *path)
{
	t_file		*pointer;

	MEM_CHK((pointer = (t_file *)malloc(sizeof(t_file))));
	pointer->path = path;
	lstat(path, pointer->f_info);
	pointer->f_entry = NULL;
	pointer->next = NULL;
	pointer->sub_dir = NULL;
	return (pointer);
}

static void		push_file(t_file **head, t_file *file)
{
	t_file		*current;

	current = *head;
	if (!current)
		*head = file;
	else
	{
		while (current->next)
			current = current->next;
		current->next = file;
	}
}

t_file			*create_file_list(t_lslist *paths, t_lsflags *flags)
{
	t_file		*head;
	t_file		*to_add;
	t_lslist	*paths_head;

	(void)flags;
	head = NULL;
	paths_head = paths;
	if (!paths)
		return (NULL);
	while (paths && paths->is_file)
	{
		to_add = new_file(paths->data);
		push_file(&head, to_add);
		paths = paths->next;
	}
	free_paths(paths_head);
	return (head);
}
