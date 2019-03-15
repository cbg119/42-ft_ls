/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:49:10 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/15 15:06:46 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (pointer);
}

void		del_files(t_file **head)
{
	t_file		*to_del;

	if (head && *head)
	{
		while (*head)
		{
			to_del = *head;
			*head = (*head)->next;
			free(to_del->f_entry);
			free(to_del->f_info);
			free(to_del->path);
			if (to_del->sub_dir)
				del_files(&(to_del->sub_dir));
			free(to_del);
		}
		head = NULL;
	}
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
			if (S_ISREG(true_head->f_info->st_mode) ||
			(S_ISDIR(true_head->f_info->st_mode) && !flags->r_r))
				true_head->sub_dir = NULL;
			else if (S_ISDIR(true_head->f_info->st_mode) && flags->r_r)
			{
				true_head->sub_dir = get_files(true_head->path);
				true_head->sub_dir = bubble_list(true_head->sub_dir);
				populate_list(true_head->sub_dir, flags);
			}
			true_head = true_head->next;
		}
	}
}
