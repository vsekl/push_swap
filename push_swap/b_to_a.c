/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:18:21 by vjose             #+#    #+#             */
/*   Updated: 2021/12/14 20:19:16 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	b_to_a_3(t_list **b, char **result, int	*flag, int *first_elem)
{
	*flag = 1;
	*first_elem = (*b)->content;
	(*b)->flag++;
	rb(b, result);
}

static void	b_to_a_2(t_list **b, t_list **a, char **result, int pivot)
{
	int	flag;
	int	first_elem;

	flag = 0;
	while (flag != 2)
	{
		if ((*b)->content >= pivot)
		{
			(*b)->flag++;
			pb(b, a, result);
		}
		else if (flag == 0)
			b_to_a_3(b, result, &flag, &first_elem);
		else if ((*b)->content == first_elem)
			flag = 2;
		else
		{
			(*b)->flag++;
			rb(b, result);
		}
	}
}

void	b_to_a(t_list **b, t_list **a, char **result)
{
	int	pivot;
	int	list_length;

	list_length = (ft_lstsize(*b));
	if (list_length <= 3)
	{
		sort_small_b(b, result);
		while (*b != NULL)
		{
			(*b)->flag++;
			pb(b, a, result);
		}
		return ;
	}
	pivot = find_pivot(*b, list_length / 2 + 1, 0);
	b_to_a_2(b, a, result, pivot);
}
