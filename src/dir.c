/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:11:09 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/15 12:02:35 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	dir_stream = opendir(path);
	path = handle_path(path);
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
