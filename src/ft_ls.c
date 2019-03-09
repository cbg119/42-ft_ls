/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:41:43 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/08 22:55:12 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*

void			get_files(char *path)
{
	DIR				*dir_pointer;
	struct dirent	*dir_file;
	struct stat		file_info;
	//t_file			*files;
	//..t_file			*temp;

	if (path[0] == '/' && !path[1])
		path = ft_strjoin(path, "/");
	if ((dir_pointer = opendir(path)) == NULL)
	{
		ft_printf("Error opening directory!");
		return ;
	}
	while ((dir_file = readdir(dir_pointer)))
	{
		path = ft_strjoin(path, dir_file->d_name);
		stat(path, &file_info);
		if (S_ISDIR(file_info.st_mode))
		{
			if (path[0] != '.')
				get_files(ft_strjoin(path, dir_file->d_name));
		}
		else
			ft_printf("%s\n", dir_file->d_name);
		free(path);
	}
	closedir(dir_pointer);
}

*/

void				get_files(char *path)
{
	DIR				*directory;
	t_entries		**list_head;
	t_entries		*to_add;
	t_file			*file;

	list_head = NULL;
	file = NULL;
	if (!(path[0] == '/' && !path[1]))
		path = ft_strjoin(path, "/");
	if (!(directory = opendir(path)))
	{
		ft_printf("Error opening directory!\n");
		return ;
	}
	while ((file->entry = readdir(directory)))
	{
		path = ft_strjoin(path, file->entry->d_name);
		stat(path, file->stat_info);
		to_add = new_list(file);
		list_add(list_head, to_add);
	}

}

int		main(int argc, char *argv[])
{
	(void)argc;

	get_files(argv[1]);
	return (0);
}

/*
int		main(void)
{
	struct dirent	*dir_hand;
	DIR				*dir_stream;
	t_file			*files;
	t_file			*temp;

	if ((dir_stream = opendir(".")) == NULL)
	{
		ft_printf("Error opening directory!\n");
		return (1);
	}
	files = new_list("\0");
	while ((dir_hand = readdir(dir_stream)))
	{
		if (*(dir_hand->d_name) != '.')
		{
			temp = new_list(dir_hand->d_name);
			list_add(&files, temp);
		}
	}
	while (files)
	{
		if (ft_strcmp(files->name, "\0") != 0)
			ft_printf("%s\n", files->name);
		files = files->next;
	}
	closedir(dir_stream);
	return (0);
}*/
