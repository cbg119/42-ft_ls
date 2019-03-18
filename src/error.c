/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:52:35 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/18 14:53:51 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_basic_error(char *illegal_token)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(illegal_token, 2);
	ft_putstr_fd(": ", 2);
	perror("");
}

void			error(char *illegal_token, int error, int entries)
{
	if (error == 0)
		return ;
	if (error == USAGE)
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putstr_fd(illegal_token, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("usage: ls [-Ralrt] [file ...]\n", 2);
		exit(1);
	}
	if (error == ENOENT)
		print_basic_error(illegal_token);
	if (error == EACCES)
	{
		if (entries >= 3)
		{
			ft_putstr_fd(illegal_token, 2);
			ft_putstr_fd(":\n", 2);
		}
		print_basic_error(illegal_token);
		if (entries >= 3)
			ft_putchar_fd('\n', 2);
	}
}
