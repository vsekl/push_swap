/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:48:45 by vjose             #+#    #+#             */
/*   Updated: 2021/12/14 21:38:30 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\t' || c == '\n' \
	|| c == '\r' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			flag;
	long int	result;
	int			i;

	flag = 1;
	result = 0;
	i = 0;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			flag = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (i > 18 && flag == 1)
			return (-1);
		if (i > 18 && flag == -1)
			return (0);
		i++;
	}
	return (result * flag);
}
