/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:37:45 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/15 15:30:59 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	TODO
**	Add flags l, R, a, r, t
*/

#include "../includes/ft_ls.h"

static int		list_count(t_lsflags *flags, int argc)
{
	return (argc - flags->param_blocks > 2);
}

static int		is_file(char *path)
{
	DIR		*dir_stream;

	errno = 0;
	dir_stream = opendir(path);
	if (dir_stream)
		closedir(dir_stream);
	return (errno == ENOTDIR);
}

void			ft_ls(char *path, t_lsflags *flags, int argc)
{
	t_file	*files;
	t_file	*head;

	files = NULL;
	if (is_file(path))
	{
		handle_file(path);
		return ;
	}
	if (errno == ENOENT)
		error(path, NON_EXISTANT);
	files = get_files(path);
	files = bubble_list(files);
	populate_list(files, flags);
	head = files;
	print_files(files, flags, list_count(flags, argc));
	del_files(&head);
}

int				main(int argc, char *argv[])
{
	int			i;
	t_lsflags	*flags;

	(void)argc;
	errno = 0;
	flags = get_flags(argc, argv);
	i = flags->param_blocks + 1;
	if ((argc == 1 && !flags->param_blocks) ||
	(argc - flags->param_blocks) == 1)
		ft_ls(".", flags, 0);
	else
	{
		while (i < argc)
		{
			ft_ls(argv[i], flags, argc);
			if (list_count(flags, argc) && i + 1 < argc)
				ft_putchar('\n');
			i++;
		}
	}
	ft_printf("a: %d\n", flags->a);
	ft_printf("l: %d\n", flags->l);
	ft_printf("r: %d\n", flags->r);
	ft_printf("t: %d\n", flags->t);
	ft_printf("R: %d\n", flags->r_r);
	free(flags);
	return (0);
}
