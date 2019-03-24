/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:00:56 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/23 17:53:29 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_file	*sort_merge(t_file *a, t_file *b, t_lsflags *flags)
{
	t_file		*result;

	result = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (!flags->r && ft_strcmp(a->name, b->name) <= 0)
	{
		result = a;
		result->next = sort_merge(a->next, b, flags);
	}
	else if (flags->r && ft_strcmp(a->name, b->name) >= 0)
	{
		result = a;
		result->next = sort_merge(a->next, b, flags);
	}
	else
	{
		result = b;
		result->next = sort_merge(a, b->next, flags);
	}
	return (result);
}

static void		merge_split(t_file *source, t_file **front, t_file **back)
{
	t_file	*fast;
	t_file	*slow;

	slow = source;
	fast = source->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

void			sort_list(t_file **head, t_lsflags *flags)
{
	t_file		*head_curr;
	t_file		*a;
	t_file		*b;

	head_curr = *head;
	if (!head_curr || !head_curr->next)
		return ;
	merge_split(head_curr, &a, &b);
	sort_list(&a, flags);
	sort_list(&b, flags);
	*head = sort_merge(a, b, flags);
}
