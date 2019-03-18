/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:19:51 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/17 17:35:18 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc, char *argv[])
{
	t_file			*files;
	t_lsflags		*flags;

	flags = get_lsflags(argc, argv);
	ft_bubblestrings(argv, argc, flags->param_blocks + 1);
	files = init_file_list(argc, argv, flags->param_blocks);
	/*
	ft_printf("a: %d\n", flags->a);
	ft_printf("l: %d\n", flags->l);
	ft_printf("r: %d\n", flags->r);
	ft_printf("t: %d\n", flags->t);
	ft_printf("R: %d\n", flags->r_r);
	ft_printf("Blocks: %d\n", flags->param_blocks);
	ft_printf("\n-----------------\n");
	for(int i = flags->param_blocks + 1; i < argc; i++)
	{
		ft_printf("%s\n", argv[i]);
	}
	*/
	display(files, flags);
	return (0);
}
