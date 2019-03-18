/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:37:45 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/18 14:55:05 by cbagdon          ###   ########.fr       */
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

	dir_stream = opendir(path);
	if (dir_stream)
		closedir(dir_stream);
	return (errno == ENOTDIR);
}

void			ft_ls(char *path, t_lsflags *flags, int argc)
{
	t_file	*files;
	t_file	*head;

	errno = 0;
	if (is_file(path))
	{
		handle_file(path);
		return ;
	}
	error(path, errno, argc - flags->param_blocks - 1);
	if (errno != 0)
		return ;
	files = get_files(path, flags);
	files = bubble_list(files);
	//populate_list(files, flags);
	head = files;
	if (list_count(flags, argc))
		ft_printf("%s:\n", path);
	print_files(files, flags);
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
		ft_bubblestrings(argv, argc, 1);
		while (i < argc)
		{
			ft_ls(argv[i], flags, argc);
			if (i + 1 < argc && errno == 0)
				ft_putchar('\n');
			i++;
		}
	}
	free(flags);
	return (0);
}
