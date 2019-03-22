/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 02:59:03 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/22 04:32:54 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_file(char *name)
{
	ft_printf("%s\n", name);
}

static void		print_dir(char *path, t_lsflags *flags, int multiple)
{
	DIR				*stream;
	t_file			*head;
	t_file			*temp;
	struct dirent	*directory;
	struct stat		info;

	head = NULL;
	if(!(stream = opendir(path)))
	{
		ls_error(path, EACCES);
		return ;
	}
	while ((directory = readdir(stream)))
	{
		if (directory->d_name[0] != '.' || (directory->d_name[0] == '.' && flags->a))
		{
			temp = new_file(path, directory->d_name);
			add_file(&head, temp);
		}
	}
	//sort list
	if (multiple)
		ft_printf("%s:\n", path);
	temp = head;
	while (head)
	{
		print_file(head->name);
		head = head->next;
	}
	while (temp)
	{
		lstat(temp->full_path, &info);
		if (S_ISDIR(info.st_mode) && flags->r_r)
			print_dir(temp->full_path, flags, 1);
		temp = temp->next;
	}
}

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
		print_file(path);
}

int		main(int argc, char *argv[])
{
	int			multiple;
	t_lsflags	*flags;

	flags = get_ls_flags(argc, argv);
	multiple = argc - (flags->param_blocks + 1) > 0;
	bsort_args(argc, argv);
	for (int i = flags->param_blocks + 1; i < argc; i++)
	{
		ft_ls(argv[i], flags, multiple);
		if (multiple && i + 1 < argc)
			ft_printf("\n");
	}
	return (0);
}
