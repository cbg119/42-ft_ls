/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 03:04:47 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/22 03:20:58 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		zero_flags(t_lsflags *flags)
{
	flags->a = 0;
	flags->l = 0;
	flags->r = 0;
	flags->t = 0;
	flags->r_r = 0;
	flags->param_blocks = 0;
}

static void		add_ls_flag(t_lsflags *flags, char flag)
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

t_lsflags		*get_ls_flags(int argc, char *argv[])
{
	int			param;
	int			character;
	t_lsflags	*flags;

	param = 1;
	MEM_CHK((flags = (t_lsflags *)malloc(sizeof(t_lsflags))));
	zero_flags(flags);
	if (argc > 1)
	{
		while (param < argc && argv[param][0] == '-' && argv[param][1])
		{
			character = 1;
			while (argv[param][character])
			{
				if (IS_FLAG(argv[param][character]))
					add_ls_flag(flags, argv[param][character]);
				else
					ls_error(&argv[param][character], FLAG_ERROR);
				character++;
			}
			param++;
			flags->param_blocks++;
		}
	}
	return (flags);
}
