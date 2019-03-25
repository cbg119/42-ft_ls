/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 03:12:06 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/24 16:20:36 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		arg_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void		lst_swap(t_list *a, t_list *b)
{
	char	*temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

static void		set_time(t_list *file_a, t_list *file_b, struct timespec *a,
struct timespec *b)
{
	struct stat		info;

	stat(file_a->content, &info);
	*a = info.st_mtimespec;
	stat(file_b->content, &info);
	*b = info.st_mtimespec;
}

void			t_bsort_args(t_list *head, t_lsflags *flags)
{
	t_list				*curr;
	struct timespec		time_a;
	struct timespec		time_b;

	curr = head;
	while (curr && curr->next)
	{
		set_time(curr, curr->next, &time_a, &time_b);
		if (!flags->r && ((time_a.tv_sec < time_b.tv_sec) ||
		(time_a.tv_sec == time_b.tv_sec && time_a.tv_nsec > time_b.tv_nsec)))
		{
			lst_swap(curr, curr->next);
			curr = head;
		}
		else if (flags->r && ((time_a.tv_sec > time_b.tv_sec) ||
		(time_a.tv_sec == time_b.tv_sec && time_a.tv_nsec < time_b.tv_nsec)))
		{
			lst_swap(curr, curr->next);
			curr = head;
		}
		else
			curr = curr->next;
	}
}

void			bsort_args(int argc, char *argv[], t_lsflags *flags)
{
	int		i;

	i = flags->param_blocks + 1;
	while (i + 1 < argc)
	{
		if (!flags->r && ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			arg_swap(&argv[i], &argv[i + 1]);
			i = flags->param_blocks + 1;
		}
		else if (flags->r && ft_strcmp(argv[i], argv[i + 1]) < 0)
		{
			arg_swap(&argv[i], &argv[i + 1]);
			i = flags->param_blocks + 1;
		}
		else
			i++;
	}
}
