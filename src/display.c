/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 01:13:46 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/25 01:37:16 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_file_type(struct stat info)
{
	if (S_ISBLK(info.st_mode))
		ft_printf("b");
	else if (S_ISCHR(info.st_mode))
		ft_printf("c");
	else if (S_ISDIR(info.st_mode))
		ft_printf("d");
	else if (S_ISLNK(info.st_mode))
		ft_printf("l");
	else if (S_ISSOCK(info.st_mode))
		ft_printf("s");
	else if (S_ISFIFO(info.st_mode))
		ft_printf("p");
	else
		ft_printf("-");
}

static void		print_permissions(struct stat info)
{
	print_file_type(info);
	ft_printf((info.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((info.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((info.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((info.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((info.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((info.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((info.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((info.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((info.st_mode & S_IXOTH) ? "x" : "-");
}

static void		print_time(struct stat info)
{
	char		*time_fields;
	char		*field;

	time_fields = (ctime(&(info.st_mtime)));
	field = ft_strsub(time_fields, 4, 12);
	ft_printf(" %s ", field);
	free(field);
}

void			print_l(int *widths, struct stat info)
{
	print_permissions(info);
	ft_printf(" %*d ", (widths[0] == 1) ? 2 : widths[0] - + 1, info.st_nlink);
	if (getpwuid(info.st_uid))
		ft_printf("%-*s", widths[1] + 2, (getpwuid(info.st_uid))->pw_name);
	else
		ft_printf("%-*s", widths[1] + 2, "error");
	ft_printf("%-*s", widths[2] + 2,
	getgrgid(info.st_gid)->gr_name);
	if (!S_ISBLK(info.st_mode) && !S_ISCHR(info.st_mode))
		ft_printf("%*i", widths[3], info.st_size);
	else
		ft_printf("%*u, %*u", 10, major(info.st_rdev), 10, minor(info.st_rdev));
	print_time(info);
}

void			print_l_link(char *path, struct stat info)
{
	(void)info;
	char	*link;

	link = ft_strnew(PATH_MAX);
	readlink(path, link, PATH_MAX);
	ft_printf(link);
	free(link);
}
