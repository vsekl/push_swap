/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:23:06 by vjose             #+#    #+#             */
/*   Updated: 2021/12/14 16:01:15 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	div_small_stack(t_list **a, t_list **b, char **result, int lst_size)
{
	int		pivot;
	t_list	*lst_last;

	pivot = find_pivot(*a, lst_size / 2, 0);
	lst_last = ft_lstlast(*a);
	while (1)
	{
		if (*a == lst_last)
		{
			if ((*a)->content <= pivot)
				pa(a, b, result);
			else
				ra(a, result);
			break ;
		}
		if ((*a)->content <= pivot)
			pa(a, b, result);
		else
			ra(a, result);
	}
	sort_small_a(a, result);
	sort_small_b(b, result);
	while (*b != NULL)
		pb(b, a, result);
}

void	sort_small_stack(t_list **a, t_list **b, char **result)
{
	int		lst_size;

	lst_size = ft_lstsize(*a);
	if (lst_size <= 3)
		sort_small_a(a, result);
	else
		div_small_stack(a, b, result, lst_size);
}
