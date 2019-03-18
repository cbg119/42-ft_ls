/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:34:27 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/18 16:24:50 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

# define MAX(a, b) (a = (b > a) ? b : a)

static void		print_recursive_files(t_file *head, t_lsflags *flags, int *wid)
{
	while (head)
	{
		if (S_ISDIR(head->f_info->st_mode))
			if (!(flags->a && flags->r_r &&
			(ft_strequ(".", head->f_entry->d_name) ||
			ft_strequ("..", head->f_entry->d_name))))
			{
				ft_printf("\n%s:\n", head->path);
				head->sub_dir = get_files(head->path, flags);
				head->sub_dir = bubble_list(head->sub_dir);
				if (flags->l)
					print_l(head, wid);
				if (head->sub_dir)
					print_files(head->sub_dir, flags);
			}
		head = head->next;
	}
}

/*
**	Assigning to n to reduce calls and potentially speed this part up.
**	Actual effectiveness to be determined.
*/

static void		get_max(int *widths, t_file *head)
{
	int		n;
	t_file	*true_head;

	true_head = head;
	while (true_head)
	{
		n = ft_intlen(true_head->f_info->st_nlink);
		MAX(widths[0], n);
		n = ft_strlen((getpwuid(true_head->f_info->st_uid)->pw_name));
		MAX(widths[1], n);
		n = ft_strlen((getgrgid(true_head->f_info->st_gid)->gr_name));
		MAX(widths[2], n);
		n = ft_intlen(true_head->f_info->st_size);
		MAX(widths[3], n);
		true_head = true_head->next;
	}
}

void			print_files(t_file *head, t_lsflags *flags)
{
	static int	widths[5] = {0};
	t_file		*true_head;

	(void)flags;
	get_max(widths, head);
	true_head = head;
	while (true_head)
	{
		if (flags->l)
			print_l(true_head, widths);
		if (S_ISDIR(true_head->f_info->st_mode))
			ft_printf("%s%s%s\n", C_CYAN, true_head->f_entry->d_name, C_RESET);
		else if (true_head->f_info->st_mode & S_IXUSR)
			ft_printf("%s%s%s\n", C_RED, true_head->f_entry->d_name, C_RESET);
		else
			ft_printf("%s\n", true_head->f_entry->d_name);
		true_head = true_head->next;
	}
	true_head = head;
	if (flags->r_r)
		print_recursive_files(true_head, flags, widths);
}
