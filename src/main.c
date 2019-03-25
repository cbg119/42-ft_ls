/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 02:59:03 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/24 19:26:39 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

//TODO: Add "total" field to t-l prints

void	ft_ls(char *path, t_lsflags *flags, int multiple)
{
	struct stat		info;

	if (lstat(path, &info) == -1)
	{
		ls_error(path, ENOENT);
		return ;
	}
	if (S_ISDIR(info.st_mode))
		print_dir(path, flags, multiple);
	else
		print_file(path, path, info, flags);
}

static t_list	*init_file_list(int argc, char *argv[], t_lsflags *flags)
{
	int				i;
	struct stat		info;
	t_list			*head;
	t_list			*to_add;

	head = NULL;
	i = flags->param_blocks + 1;
	while (i < argc)
	{
		if (lstat(argv[i], &info) != -1)
		{
			to_add = ft_lstnew(argv[i], ft_strlen(argv[i]) + 1);
			ft_lstpush(&head, to_add);
		}
		else
			ls_error(argv[i], ENOENT);
		i++;
	}
	return (head);
}

static void		del_file_list(t_list **head)
{
	t_list	*to_del;

	if (!*head)
		return ;
	while (*head)
	{
		to_del = *head;
		*head = (*head)->next;
		free(to_del->content);
		free(to_del);
	}
}

int		main(int argc, char *argv[])
{
	int			multiple;
	t_lsflags	*flags;
	t_list		*head;
	t_list		*temp;

	flags = get_ls_flags(argc, argv);
	multiple = argc - (flags->param_blocks + 1) > 1;
	bsort_args(argc, argv, flags);
	head = init_file_list(argc, argv, flags);
	if (flags->t)
		t_bsort_args(head, flags);
	temp = head;
	while (temp)
	{
		ft_ls(temp->content, flags, multiple);
		temp = temp->next;
	}
	del_file_list(&head);
	free(flags);
	return (0);
}
