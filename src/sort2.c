/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:00:56 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/25 16:40:21 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		set_time(t_file *file_a, t_file *file_b, struct timespec *a,
struct timespec *b)
{
	struct stat		info;

	lstat(file_a->full_path, &info);
	*a = info.st_mtimespec;
	lstat(file_b->full_path, &info);
	*b = info.st_mtimespec;
}

static t_file	*t_sort_merge(t_file *a, t_file *b, t_lsflags *flags)
{
	struct timespec		time_a;
	struct timespec		time_b;
	t_file				*result;

	result = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	set_time(a, b, &time_a, &time_b);
	if ((!flags->r && ((time_a.tv_sec > time_b.tv_sec) ||
	(time_a.tv_sec == time_b.tv_sec && time_a.tv_nsec > time_b.tv_nsec))) ||
	(flags->r && ((time_a.tv_sec < time_b.tv_sec) ||
	(time_a.tv_sec == time_b.tv_sec && time_a.tv_nsec < time_b.tv_nsec))))
	{
		result = a;
		result->next = t_sort_merge(a->next, b, flags);
	}
	else
	{
		result = b;
		result->next = t_sort_merge(a, b->next, flags);
	}
	return (result);
}

static t_file	*sort_merge(t_file *a, t_file *b, t_lsflags *flags)
{
	t_file		*result;

	result = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if ((!flags->r && ft_strcmp(a->name, b->name) <= 0) ||
	(flags->r && ft_strcmp(a->name, b->name) >= 0))
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
	if (!flags->t && !flags->f)
		*head = sort_merge(a, b, flags);
	else if (!flags->f)
		*head = t_sort_merge(a, b, flags);
}
