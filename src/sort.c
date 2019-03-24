/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 03:12:06 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/24 10:59:54 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		arg_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
static void		set_time(int i, char *argv[], struct timespec *a,
struct timespec *b)
{
	struct stat		info;

	if (lstat(argv[i], &info) == -1)
		a = NULL;
	else
		*a = info.st_mtimespec.tv_nsec;
	if (lstat(argv[i + 1], &info) == -1)
		*b = 0;
	else
		*b = info.st_mtimespec.tv_nsec;
}
*/

/*
static void		t_bsort_args(int argc, char *argv[], t_lsflags *flags)
{
	int				i;
	struct stat		a;
	struct stat		b;
	long			time_a;
	long			time_b;

	i = flags->param_blocks + 1;
	while (i + 1 < argc)
	{
		lstat(argv[i], &a);
		lstat(argv[i + 1], &b);
		time_a = a.st_mtimespec.tv_sec;
		time_b = b.st_mtimespec
		if (!flags->r && ((a.st_mtimespec.tv_sec < b.st_mtimespec.tv_sec)) ||
		(a.st_atimespec.tv_sec == b.st_mtimespec && a.st_mtimespec.tv_nsec <))
		{
			arg_swap(&argv[i], &argv[i + 1]);
			i = flags->param_blocks + 1;
		}
		else if (flags->r && (a.st_mtimespec.tv_sec > b.st_mtimespec.tv_sec))
		{
			arg_swap(&argv[i], &argv[i + 1]);
			i = flags->param_blocks + 1;
		}
		else
			i++;
	}
}
*/

void			bsort_args(int argc, char *argv[], t_lsflags *flags)
{
	int		i;

	i = flags->param_blocks + 1;
	/*
	if (flags->t)
	{
		t_bsort_args(argc, argv, flags);
		return ;
	}
	*/
	while (i + 1 < argc)
	{
		if (!flags->r && ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			arg_swap(&argv[i], &argv[i + 1]);
			i = flags->param_blocks + 1;
		}
		else if (flags->r && ft_strcmp(argv[i], argv[i + 1]) < 0)
		{
			arg_swap(&argv[i], &argv[i + 1]);
			i = flags->param_blocks + 1;
		}
		else
			i++;
	}
}
