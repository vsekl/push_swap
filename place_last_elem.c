/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_last_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:38:39 by vjose             #+#    #+#             */
/*   Updated: 2021/12/14 19:36:01 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *a)
{
	int	min;

	min = a->content;
	while (a != NULL)
	{
		if (a->content < min)
			min = a->content;
		a = a->next;
	}
	return (min);
}

static int	find_position(t_list *a, int min)
{
	int	position;

	position = 1;
	while (a != NULL)
	{
		if (a->content == min)
		{
			a->flag = -1;
			return (position);
		}
		position++;
		a = a->next;
	}
	return (position);
}

void	place_last_elem(t_list **a, int min, char **result)
{
	int	len;
	int	position;

	len = ft_lstsize(*a);
	position = find_position(*a, min);
	if (position < len / 2)
	{
		while (position > 0)
		{
			ra(a, result);
			position--;
		}
	}
	else
	{
		while (len > position)
		{
			rra(a, result);
			position++;
		}
	}
}
