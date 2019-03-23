/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 03:12:06 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/22 17:29:00 by cbagdon          ###   ########.fr       */
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

static void		list_swap(t_file *a, t_file *b)
{
	char	*path;
	char	*name;
	char	*full_path;

	path = a->path;
	name = a->name;
	full_path = a->full_path;
	a->path = b->path;
	a->name = b->name;
	a->full_path = b->full_path;
	b->path = path;
	b->name = name;
	b->full_path = full_path;
}

void			bsort_args(int argc, char *argv[])
{
	int		i;

	i = 1;
	while (i + 1 < argc)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			arg_swap(&argv[i], &argv[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void			sort_list(t_file *head)
{
	t_file		*curr;

	curr = head;
	while (curr && curr->next)
	{
		if (ft_strcmp(curr->name, curr->next->name) > 0)
		{
			list_swap(curr, curr->next);
			curr = head;
		}
		else
			curr = curr->next;
	}
}
