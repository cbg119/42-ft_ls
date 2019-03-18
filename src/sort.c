/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:33:14 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/16 17:00:39 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_bubblestrings(char **table, int size, int start)
{
	char	*temp;
	int		i;

	if (size <= 1)
		return ;
	i = start;
	while (i < size - 1)
	{
		if (ft_strcmp(table[i], table[i + 1]) > 0)
		{
			temp = table[i];
			table[i] = table[i + 1];
			table[i + 1] = temp;
			i = start;
		}
		else
			i++;
	}
}
