/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:34:27 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/17 21:32:26 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			print_l(t_file *file)
{
	ft_printf((S_ISDIR(file->f_info->st_mode)) ? "d" : "-");
    ft_printf((file->f_info->st_mode & S_IRUSR) ? "r" : "-");
    ft_printf((file->f_info->st_mode & S_IWUSR) ? "w" : "-");
    ft_printf((file->f_info->st_mode & S_IXUSR) ? "x" : "-");
    ft_printf((file->f_info->st_mode & S_IRGRP) ? "r" : "-");
    ft_printf((file->f_info->st_mode & S_IWGRP) ? "w" : "-");
    ft_printf((file->f_info->st_mode & S_IXGRP) ? "x" : "-");
    ft_printf((file->f_info->st_mode & S_IROTH) ? "r" : "-");
    ft_printf((file->f_info->st_mode & S_IWOTH) ? "w" : "-");
    ft_printf((file->f_info->st_mode & S_IXOTH) ? "x  " : "-  ");
	ft_printf("%d ", file->f_info->st_nlink);
	ft_printf("%s ", file->o_uid->pw_name);
}

void			print_files(t_file *head, t_lsflags *flags)
{
	t_file		*true_head;

	(void)flags;
	true_head = head;
	while (true_head)
	{
		//ft_printf(S_ISDIR(true_head->f_info->st_mode) ? C_CYAN : "");
		if (flags->l)
			print_l(true_head);
		ft_printf("%s\n", true_head->f_entry->d_name);
		//ft_printf(S_ISDIR(true_head->f_info->st_mode) ? C_RESET : "");
		true_head = true_head->next;
	}
	true_head = head;
	while (true_head && flags->r_r)
	{
		if (S_ISDIR(true_head->f_info->st_mode))
		{
			ft_printf("\n%s:\n", true_head->path);
			if (flags->l)
			print_l(true_head);
			print_files(true_head->sub_dir, flags);
		}
		true_head = true_head->next;
	}
	/*
	while (true_head)
	{
		ft_printf("%s\n", true_head->f_entry->d_name);
		if (S_ISREG(true_head->f_info->st_mode))
			true_head->sub_dir = NULL;
		true_head = true_head->next;
	}
	while (head && flags->r_r)
	{
		if (S_ISDIR(head->f_info->st_mode))
		{
			ft_printf("\n%s:\n", head->path);
			head->sub_dir = get_files(head->path);
			head->sub_dir = bubble_list(head->sub_dir);
			print_files(head->sub_dir, flags);
		}
		head = head->next;
	}
	*/
}
