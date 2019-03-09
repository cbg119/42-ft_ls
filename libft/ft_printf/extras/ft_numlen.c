/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:02:32 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/03 14:11:03 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_numlen(unsigned long long num)
{
	int					i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}
