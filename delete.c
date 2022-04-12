/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:07:56 by vjose             #+#    #+#             */
/*   Updated: 2021/11/29 19:07:56 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	trim_ops(char **result)
{
	if ((**result == '0' && *(*result + 1) == '1') || \
		(**result == '1' && *(*result + 1) == '0') || \
		(**result == '2' && *(*result + 1) == '3') || \
		(**result == '3' && *(*result + 1) == '2'))
	{
		*result = *result + 2;
		return (1);
	}
	if ((**result == '3' && *(*result + 1) == '7') || \
		(**result == '7' && *(*result + 1) == '3'))
	{
		*result = *result + 2;
		write(1, "rrr\n", 4);
		return (1);
	}
	if ((**result == '5' && *(*result + 1) == '6') || \
		(**result == '6' && *(*result + 1) == '5'))
	{
		*result = *result + 2;
		write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}

void	print_ops(char **result)
{
	if (**result == '0')
		write(1, "pb\n", 3);
	else if (**result == '1')
		write(1, "pa\n", 3);
	else if (**result == '2')
		write(1, "ra\n", 3);
	else if (**result == '3')
		write(1, "rra\n", 4);
	else if (**result == '4')
		write(1, "rb\n", 3);
	else if (**result == '5')
		write(1, "sa\n", 3);
	else if (**result == '6')
		write(1, "sb\n", 3);
	else if (**result == '7')
		write(1, "rrb\n", 4);
	(*result)++;
}

void	delete(char **result)
{
	char	*ptr;

	ptr = *result;
	while (**result != '\0')
	{	
		if (trim_ops(result) == 0)
			print_ops(result);
	}
	free(ptr);
}
