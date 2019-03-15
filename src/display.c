/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:34:27 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/15 15:30:49 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


void			print_files(t_file *head, t_lsflags *flags, int file_count)
{
	t_file		*true_head;

	(void)flags;
	if (!head)
		return ;
	true_head = head;
	if (file_count == 1)
		ft_printf("%s:\n", true_head->path);
	while (true_head)
	{
		ft_printf("%s\n", true_head->f_entry->d_name);
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
