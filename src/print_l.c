/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:44:17 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/18 16:17:37 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_permissions(t_file *file)
{
	if (S_ISDIR(file->f_info->st_mode))
		ft_printf("d");
	else if (S_ISLNK(file->f_info->st_mode))
		ft_printf("l");
	else
		ft_printf("-");
	ft_printf((file->f_info->st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((file->f_info->st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((file->f_info->st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((file->f_info->st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((file->f_info->st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((file->f_info->st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((file->f_info->st_mode & S_IROTH) ? "r" : "-");
	ft_printf((file->f_info->st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((file->f_info->st_mode & S_IXOTH) ? "x" : "-");
}

static void		print_time(t_file *file)
{
	char		**time_fields;
	char		**hour_min_sec;

	time_fields = ft_strsplit(ctime(&(file->f_info->st_mtime)), ' ');
	hour_min_sec = ft_strsplit(time_fields[3], ':');
	ft_printf(" %s ", time_fields[1]);
	ft_printf("%2s ", time_fields[2]);
	ft_printf("%s:%s ", hour_min_sec[0], hour_min_sec[1]);
	free(time_fields);
	free(hour_min_sec);
}

void			print_l(t_file *file, int *widths)
{
	print_permissions(file);
	ft_printf(" %*d ", (widths[0] == 1) ? 2 : widths[0] + 1, file->f_info->st_nlink);
	ft_printf("%-*s", widths[1] + 2,
	(getpwuid(file->f_info->st_uid))->pw_name);
	ft_printf("%-*s", widths[2] + 2,
	getgrgid(file->f_info->st_gid)->gr_name);
	ft_printf("%*i", widths[3], file->f_info->st_size);
	print_time(file);
}
