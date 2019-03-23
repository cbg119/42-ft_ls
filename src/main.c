/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 02:59:03 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/22 17:47:25 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_ls(char *path, t_lsflags *flags, int multiple)
{
	struct stat		info;

	if (stat(path, &info) == -1)
	{
		ls_error(path, ENOENT);
		return ;
	}
	if (S_ISDIR(info.st_mode))
		print_dir(path, flags, multiple);
	else
		print_file(path, info);
}

int		main(int argc, char *argv[])
{
	int			multiple;
	t_lsflags	*flags;

	flags = get_ls_flags(argc, argv);
	multiple = argc - (flags->param_blocks + 1) > 1;
	bsort_args(argc, argv);
	for (int i = flags->param_blocks + 1; i < argc; i++)
	{
		ft_ls(argv[i], flags, multiple);
	}
	return (0);
}
