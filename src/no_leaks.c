/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:22:35 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/20 00:25:44 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	free_paths(t_lslist *path)
{
	t_lslist	*to_del;

	while (path)
	{
		to_del = path;
		path = path->next;
		free(to_del);
	}
}
