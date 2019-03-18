/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:47:33 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/17 20:58:43 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		is_lsflag(char flag)
{
	return (flag == 'a' || flag == 'l' || flag == 'r' || flag == 't' ||
	flag == 'R');
}

static void		lsadd_flag(t_lsflags *flags, char flag)
{
	if (flag == 'a')
		flags->a = 1;
	else if (flag == 'l')
		flags->l = 1;
	else if (flag == 'r')
		flags->r = 1;
	else if (flag == 't')
		flags->t = 1;
	else if (flag == 'R')
		flags->r_r = 1;
}

static void		set_flags(t_lsflags *flags)
{
	flags->a = 0;
	flags->l = 0;
	flags->r = 0;
	flags->t = 0;
	flags->r_r = 0;
	flags->param_blocks = 0;
}

t_lsflags		*get_flags(int argc, char *argv[])
{
	int			i;
	int			j;
	t_lsflags	*flags;

	i = 1;
	MEM_CHK((flags = (t_lsflags *)malloc(sizeof(t_lsflags))));
	set_flags(flags);
	if (argc > 1)
	{
		while (i < argc && argv[i][0] == '-' && argv[i][1])
		{
			j = 1;
			while (argv[i][j])
			{
				if (is_lsflag(argv[i][j]))
					lsadd_flag(flags, argv[i][j]);
				else
					error(&argv[i][j], USAGE, argc - flags->param_blocks - 1);
				j++;
			}
			i++;
			flags->param_blocks++;
		}
	}
	return (flags);
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
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(illegal_token, 2);
		ft_putstr_fd(": ", 2);
		perror("");
	}
	if (error == EACCES)
	{
		if (entries >= 3)
		{
			ft_putstr_fd(illegal_token, 2);
			ft_putstr_fd(":\n", 2);
		}
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(illegal_token, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		if (entries >= 3)
			ft_putchar_fd('\n', 2);
	}
}
