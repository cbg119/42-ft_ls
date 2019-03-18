/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:49:10 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/17 22:02:18 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/ft_ls.h"

t_file		*switch_links(t_file *a, t_file *b)
{
	a->next = b->next;
	b->next = a;
	return (b);
}

t_file		*new_file(char *path)
{
	t_file		*pointer;

	MEM_CHK((pointer = (t_file *)malloc(sizeof(t_file))));
	pointer->path = path;
	pointer->next = NULL;
	pointer->sub_dir = NULL;
	return (pointer);
}

void		del_files(t_file **head)
{
	t_file		*temp;
	while (*head != NULL)
	{
		temp = *head;
		*head = ((*head)->next);
		free(temp->path);
		free(temp->f_entry);
		free(temp->f_info);
		if (temp->sub_dir)
			del_files(&(temp->sub_dir));
		free(temp);
	}
	head = NULL;
}

void		add_file(t_file **head, t_file *file)
{
	file->next = *head;
	*head = file;
}

void		populate_list(t_file *head, t_lsflags *flags)
{
	t_file	*true_head;

	if (head)
	{
		true_head = head;
		while (true_head)
		{
			if (S_ISDIR(true_head->f_info->st_mode) && flags->r_r)
			{
				if (!(flags->a && flags->r_r && (ft_strequ(".", true_head->f_entry->d_name) || ft_strequ("..", true_head->f_entry->d_name))))
				{
					true_head->sub_dir = get_files(true_head->path, flags);
					true_head->sub_dir = bubble_list(true_head->sub_dir);
					populate_list(true_head->sub_dir, flags);
				}
			}
			true_head = true_head->next;
		}
	}
}
