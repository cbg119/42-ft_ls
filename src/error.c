/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 03:06:17 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/25 01:08:54 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		error_nonexistent(char *illegal_token)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(illegal_token, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

static void		flag_error(char flag)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(flag, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-Ralrt] [file ...]\n", 2);
	exit(1);
}

static void		access_error(char *path)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}

static void		file_descriptor_error(char *path, int error)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(path, 2);
	if (error == EBADF)
		ft_putstr_fd(": Bad file descriptor\n", 2);
}

void			ls_error(char *illegal_token, int error)
{
	if (error == ENOENT)
		error_nonexistent(illegal_token);
	else if (error == FLAG_ERROR)
		flag_error(*illegal_token);
	else if (error == EACCES)
		access_error(illegal_token);
	else if (error == EBADF)
		file_descriptor_error(illegal_token, error);
}
