/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:10:27 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/23 17:53:17 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			print_file(char *full_path,
char *name, struct stat info, t_lsflags *flags)
{
	int widths[4] = {10, 10, 10, 10};

	if (flags->l)
		print_l(widths, info);
		/*
	if (S_ISLNK(info.st_mode))
		ft_printf("%s%s%s", C_MAGENTA, name, C_WHITE);
	else if (S_ISDIR(info.st_mode))
		ft_printf("%s%s%s", C_CYAN, name, C_WHITE);
	else if (info.st_mode & S_IXUSR)
		ft_printf("%s%s%s", C_RED, name, C_WHITE);
	else
	*/
	ft_printf("%s", name);
	if (flags->l && S_ISLNK(info.st_mode))
	{
		ft_printf(" -> ");
		print_l_link(full_path, info);
	}
	ft_printf("\n");
}

t_file			*get_dir(char *path, t_lsflags *flags)
{
	DIR				*stream;
	struct dirent	*dir;
	t_file			*head;
	t_file			*temp;

	head = NULL;
	errno = 0;
	if (!(stream = opendir(path)))
	{
		ls_error(path, EACCES);
		return (NULL);
	}
	while ((dir = readdir(stream)))
	{
		if (dir->d_name[0] != '.' || (dir->d_name[0] == '.' && flags->a))
		{
			temp = new_file(path, dir->d_name);
			add_file(&head, temp);
		}
	}
	sort_list(&head, flags);
	closedir(stream);
	return (head);
}

static void		recur_and_free(t_file *head, t_lsflags *flags)
{
	struct stat		info;
	t_file			*temp;
	t_file			*to_del;

	temp = head;
	while (temp)
	{
		if (!(ft_strequ(".", temp->name) || ft_strequ("..", temp->name)))
		{
			lstat(temp->full_path, &info);
			if (S_ISDIR(info.st_mode) && flags->r_r)
				print_dir(temp->full_path, flags, 1);
		}
		to_del = temp;
		temp = temp->next;
		free(to_del->full_path);
		free(to_del->name);
		free(to_del->path);
		free(to_del);
	}
}

void			print_dir(char *path, t_lsflags *flags, int multiple)
{
	t_file			*temp;
	t_file			*head;
	struct stat		info;

	if (multiple)
		ft_printf("%s:\n", path);
	head = get_dir(path, flags);
	temp = head;
	if (!head && errno == 0)
		ft_printf("\n");
	else
	{
		while (temp)
		{
			lstat(temp->full_path, &info);
			print_file(temp->full_path, temp->name, info, flags);
			temp = temp->next;
			if (!temp && multiple)
				ft_printf("\n");
		}
		recur_and_free(head, flags);
	}
}
