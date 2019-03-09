/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:49:10 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/08 16:46:51 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_entries		*new_list(t_file *file)
{
	t_entries	*element;

	MEM_CHK((element = (t_entries *)malloc(sizeof(t_entries))));
	element->file = file;
	element->next = NULL;
	return (element);
}

void			list_add(t_entries **head, t_entries *new)
{
	new->next = *head;
	*head = new;
}
