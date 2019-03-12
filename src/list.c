/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:49:10 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/11 19:11:18 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_file			*switch_links(t_file *a, t_file *b)
{
	a->next = b->next;
	b->next = a;
	return (b);
}

t_file			*new_file(char *path)
{
	t_file		*pointer;

	MEM_CHK((pointer = (t_file *)malloc(sizeof(t_file))));
	pointer->path = path;
	pointer->next = NULL;
	return (pointer);
}

void			del_files(t_file **head)
{
	t_file		*to_del;

	if (head && *head)
	{
		while (*head)
		{
			to_del = *head;
			*head = (*head)->next;
			free(to_del->f_entry);
			free(to_del->path);
			free(to_del->f_info);
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

t_file 		*bubble_list(t_file *head)
{
	if (!head)
		return (NULL);
	if (head->next && ft_strcmp(head->f_entry->d_name, head->next->f_entry->d_name) > 0)
		head = switch_links(head, head->next);
	head->next = bubble_list(head->next);
	if (head->next && ft_strcmp(head->f_entry->d_name, head->next->f_entry->d_name) > 0)
	{
		head = switch_links(head, head->next);
		head->next = bubble_list(head->next);
	}
	return (head);
}
