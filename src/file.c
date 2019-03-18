/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:30:27 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/18 14:27:47 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	handle_file(char *path)
{
	t_file			*head;
	struct stat		info;

	head = NULL;
	stat(path, &info);
	ft_printf("%s\n", path);
}
