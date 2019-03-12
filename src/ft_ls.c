/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:37:45 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/11 18:55:47 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file			*get_files(char *path)
{
	DIR				*dir_stream;
	struct dirent	*to_add;
	t_file			*file;
	t_file			*head;
	char			*full_path;

	head = NULL;
	if (!(path[0] == '/' && !path[1]))
		path = ft_strjoin(path, "/");
	MEM_CHK((dir_stream = opendir(path)));
	while ((to_add = readdir(dir_stream)))
	{
		full_path = ft_strjoin(path, to_add->d_name);
		file = new_file(full_path);
		MEM_CHK((file->f_entry =
		(struct dirent *)malloc(sizeof(struct dirent))));
		MEM_CHK((file->f_info =
		(struct stat *)malloc(sizeof(struct stat))));
		ft_memcpy(file->f_entry, to_add, sizeof(struct dirent));
		stat(full_path, file->f_info);
		add_file(&head, file);
	}
	free(path);
	closedir(dir_stream);
	return (head);
}

int				main(int argc, char *argv[])
{
	t_file		*files;
	t_file		*head;

	(void)argc;
	files = get_files(argv[1]);
	files = bubble_list(files);
	head = files;
	while (files)
	{
		ft_printf("%s\n", files->f_entry->d_name);
		files = files->next;
	}
	del_files(&head);
	return (0);
}
