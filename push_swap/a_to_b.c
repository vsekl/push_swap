/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:16:28 by vjose             #+#    #+#             */
/*   Updated: 2021/12/14 20:17:41 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_len(t_list *a)
{
	int	flag;
	int	counter;

	counter = 0;
	flag = a->flag;
	while (a->flag == flag)
	{
		a = a->next;
		counter++;
	}
	return (counter);
}

static void	a_to_b_small(t_list **a, char **result, int list_length)
{
	if (list_length == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a, result);
	}
	while (list_length > 0)
	{
		ra(a, result);
		list_length--;
	}
}

static int	push_a(t_list **a, t_list **b, char **result, int list_length)
{
	int	counter;
	int	pivot;
	int	flag;

	counter = 0;
	pivot = find_pivot(*a, list_length / 2 + 1, 0);
	flag = (*a)->flag;
	while ((*a)->flag == flag)
	{
		if ((*a)->content <= pivot)
			pa(a, b, result);
		else if (flag == 0)
		{
			counter++;
			ra(a, result);
		}
		else
		{
			ra(a, result);
			counter++;
		}
	}
	return (counter);
}

void	a_to_b(t_list **a, t_list **b, char **result)
{
	int	list_length;
	int	counter;

	list_length = find_len(*a);
	if (list_length <= 2)
	{
		a_to_b_small(a, result, list_length);
		return ;
	}
	counter = push_a(a, b, result, list_length);
	while (counter != 0)
	{
		rra(a, result);
		counter--;
	}
}
