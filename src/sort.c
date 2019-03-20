/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:39:48 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/19 16:47:43 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	isort_arguments(int argc, char *argv[], int start)
{
	int		i;
	int		j;
	char	*key;

	i = start + 1;
	while (i < argc)
	{
		key = argv[i];
		j = i - 1;
		while (j >= 0 && (ft_strcmp(argv[j], key) > 0))
		{
			argv[j + 1] = argv[j];
			j -= 1;
		}
		argv[j + 1] = key;
		i++;
	}
}
