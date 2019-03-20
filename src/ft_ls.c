/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:31:00 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/20 00:14:02 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_lslist		*create_path_list(int argc, char *argv[], int start)
{
	t_lslist		*file_head;
	t_lslist		*dir_head;
	t_lslist		*path;
	struct stat		temp;

	file_head = NULL;
	dir_head = NULL;
	argc--;
	while (argc >= start)
	{
		stat(argv[argc], &temp);
		path = ls_lstnew(argv[argc], (S_ISREG(temp.st_mode)) ? 1 : 0);
		if (S_ISREG(temp.st_mode))
			ls_lstadd(&file_head, path);
		else
			ls_lstadd(&dir_head, path);
		argc--;
	}
	file_head = ls_lstjoin(&file_head, &dir_head);
	return (file_head);
}

int					main(int argc, char *argv[])
{
	int			i;
	int			errored;
	t_lslist	*path;
	t_lsflags	*flags;
	t_file		*head;

	errored = 0;
	flags = get_ls_flags(argc, argv);
	isort_arguments(argc, argv, flags->param_blocks + 1);
	i = flags->param_blocks + 1;
	while (i < argc)
		open_error_check(argv[i++], &errored);
	path = create_path_list(argc, argv, flags->param_blocks + 1 + errored);
	head = create_file_list(path, flags);
	while (head)
	{
		ft_printf("%s\n", head->path);
		head = head->next;
	}
	return (0);
}
