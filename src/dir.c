/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:10:27 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/23 01:27:09 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_file(char *name, struct stat info, t_lsflags *flags)
{
	int widths[4] = {0};
	if (flags->l)
		print_l(widths, info);
	if (S_ISDIR(info.st_mode))
		ft_printf("%s%s%s\n", C_CYAN, name, C_WHITE);
	else if (info.st_mode & S_IXUSR)
		ft_printf("%s%s%s\n", C_RED, name, C_WHITE);
	else
	ft_printf("%s\n", name);
}

t_file		*get_dir(char *path, t_lsflags *flags)
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
	sort_list(head);
	closedir(stream);
	return (head);
}

void		print_dir(char *path, t_lsflags *flags, int multiple)
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
		while (head)
		{
			lstat(head->full_path, &info);
			print_file(head->name, info, flags);
			head = head->next;
			if (!head && multiple)
				ft_printf("\n");
		}
		while (temp)
		{
			lstat(temp->full_path, &info);
			if (S_ISDIR(info.st_mode) && flags->r_r)
				print_dir(temp->full_path, flags, 1);
			temp = temp->next;
		}
	}
}
