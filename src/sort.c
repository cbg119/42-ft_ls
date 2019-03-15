/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:28:15 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/15 14:28:39 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file			*bubble_list(t_file *head)
{
	if (!head)
		return (NULL);
	if (head->next &&
	ft_strcmp(head->f_entry->d_name, head->next->f_entry->d_name) > 0)
		head = switch_links(head, head->next);
	head->next = bubble_list(head->next);
	if (head->next &&
	ft_strcmp(head->f_entry->d_name, head->next->f_entry->d_name) > 0)
	{
		head = switch_links(head, head->next);
		head->next = bubble_list(head->next);
	}
	return (head);
}
