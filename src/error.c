/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:28:05 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/20 00:13:50 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	flag_error(char illegal_flag)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(illegal_flag, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-Ralrt] [file ...]\n", 2);
	exit(1);
}

void	open_error_check(char *path, int *errored)
{
	struct stat		temp;

	errno = 0;
	if (stat(path, &temp) == -1 && errno == ENOENT)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		*errored += 1;
	}
}
