/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_size_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:39:13 by vjose             #+#    #+#             */
/*   Updated: 2021/12/14 16:03:13 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_a_size_3(t_list **a, char **result)
{
	if ((*a)->next->next->content < (*a)->next->content)
	{
		if ((*a)->next->content < (*a)->content)
		{
			sa(a, result);
			rra(a, result);
		}
		else if ((*a)->content < (*a)->next->next->content)
		{
			rra(a, result);
			sa(a, result);
		}
		else
			rra(a, result);
		return ;
	}
	if ((*a)->content < (*a)->next->content)
		return ;
	else if ((*a)->content < (*a)->next->next->content)
		sa(a, result);
	else
		ra(a, result);
}

static void	sort_stack_b_size_3(t_list **b, char **result)
{
	if ((*b)->content < (*b)->next->content)
	{
		if ((*b)->next->content < (*b)->next->next->content)
		{
			sb(b, result);
			rrb(b, result);
		}
		else if ((*b)->content < (*b)->next->next->content)
			rb(b, result);
		else
			sb(b, result);
		return ;
	}
	if ((*b)->next->next->content > (*b)->content)
		rrb(b, result);
	else if ((*b)->next->content < (*b)->next->next->content)
	{
		sb(b, result);
		rb(b, result);
	}
}

void	sort_small_a(t_list **a, char **result)
{
	int	stack_size;

	stack_size = ft_lstsize(*a);
	if (stack_size == 3)
		sort_stack_a_size_3(a, result);
	else if (stack_size == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a, result);
	}
}

void	sort_small_b(t_list **b, char **result)
{
	int	stack_size;

	stack_size = ft_lstsize(*b);
	if (stack_size == 3)
		sort_stack_b_size_3(b, result);
	if (stack_size == 2)
	{
		if ((*b)->content < (*b)->next->content)
			sb(b, result);
	}
}
