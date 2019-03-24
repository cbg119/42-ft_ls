/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 03:12:06 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/23 17:59:05 by cbagdon          ###   ########.fr       */
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
