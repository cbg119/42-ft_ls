/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:22:38 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/20 00:19:00 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_lslist	*ls_lstnew(void *content, int is_file)
{
	t_lslist	*pointer;

	MEM_CHK((pointer = (t_lslist *)malloc(sizeof(t_list))));
	pointer->data = content;
	pointer->is_file = is_file;
	pointer->next = NULL;
	return (pointer);
}

void		ls_lstadd(t_lslist **head, t_lslist *to_add)
{
	to_add->next = *head;
	*head = to_add;
}

void		ls_lstpush(t_lslist **head, t_lslist *to_add)
{
	if (*head)
	{
		while ((*head)->next)
			*head = (*head)->next;
		(*head)->next = to_add;
	}
	else
		*head = to_add;
}

t_lslist	*ls_lstjoin(t_lslist **file, t_lslist **dir)
{
	t_lslist	*temp;

	if (!*file && !*dir && !errno)
	{
		temp = ls_lstnew(".", 0);
		return (temp);
	}
	else if (!*file && !*dir && errno)
		return (NULL);
	else if (*file && !*dir)
		return (*file);
	else if (*dir && !*file)
		return (*dir);
	temp = *file;
	while ((*file)->next)
		(*file) = (*file)->next;
	(*file)->next = *dir;
	return (temp);
}
