/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:37:45 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/13 14:38:52 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	TODO
**	Add flags l, R, a, r, t
*/

#include "../includes/ft_ls.h"
#define MEM(c)	if (!c) return (NULL)

static char		*handle_path(char *path)
{
	if (!(path[0] == '/' && !path[1]))
		path = ft_strjoin(path, "/");
	else
		path = ft_strdup(path);
	return (path);
}

t_file			*get_files(char *path)
{
	DIR				*dir_stream;
	struct dirent	*to_add;
	t_file			*file;
	t_file			*head;
	char			*full_path;

	head = NULL;
	path = handle_path(path);
	MEM_CHK((dir_stream = opendir(path)));
	while ((to_add = readdir(dir_stream)))
	{
		if (to_add->d_name[0] == '.')
			continue ;
		full_path = ft_strjoin(path, to_add->d_name);
		file = new_file(full_path);
		MEM((file->f_entry = (struct dirent *)malloc(sizeof(struct dirent))));
		MEM((file->f_info = (struct stat *)malloc(sizeof(struct stat))));
		ft_memcpy(file->f_entry, to_add, sizeof(struct dirent));
		stat(full_path, file->f_info);
		add_file(&head, file);
	}
	free(path);
	closedir(dir_stream);
	return (head);
}

void			print_files(t_file *head)
{
	t_file		*true_head;

	if (!head)
		return ;
	true_head = head;
	while (true_head)
	{
		ft_printf("%s\n", true_head->f_entry->d_name);
		if (S_ISREG(true_head->f_info->st_mode))
			true_head->sub_dir = NULL;
		true_head = true_head->next;
	}
	while (head)
	{
		if (S_ISDIR(head->f_info->st_mode))
		{
			ft_printf("\n%s:\n", head->path);
			head->sub_dir = get_files(head->path);
			head->sub_dir = bubble_list(head->sub_dir);
			print_files(head->sub_dir);
		}
		head = head->next;
	}
}

int				main(int argc,
char *argv[])
{
	t_file		*files;
	t_file		*head;

	(void)argc;
	files = get_files(argv[1]);
	files = bubble_list(files);
	head = files;
	print_files(files);
	del_files(&head);
	return (0);
}
