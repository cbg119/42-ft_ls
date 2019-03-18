/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:30:44 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/17 17:39:18 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file			*read_dir(char *path, t_lsflags *flags)
{
	DIR				*directory;
	struct dirent	*entry;
	t_file			*head;

	(void)flags;
	head = NULL;
	directory = opendir(path);
	while ((entry = readdir(directory)))
	{
		add_new_file(&head, path);
	}
	return (head);
}

void			display(t_file *files, t_lsflags *flags)
{
	(void)flags;
	while (files)
	{
		if (S_ISREG(files->f_info->st_mode))
			ft_printf("%s\n", files->path);
		files = files->next;
	}
}
