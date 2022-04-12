/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:38:36 by vjose             #+#    #+#             */
/*   Updated: 2021/11/29 18:38:36 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **a, t_list **b, char **result)
{
	int		last;
	int		stack_size;
	int		flag;

	stack_size = ft_lstsize(*a);
	if (stack_size <= 6)
		sort_small_stack(a, b, result);
	else
	{	
		last = find_min(*a);
		place_last_elem(a, last, result);
		while ((*a)->content != last)
		{
			a_to_b(a, b, result);
			if (*b == NULL)
				continue ;
			while (*b != NULL)
				b_to_a(b, a, result);
			flag = (*a)->flag;
			while (flag == (*a)->flag)
				ra(a, result);
		}
	}
	delete(result);
	free_stack(*a);
}	

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*result;

	a = NULL;
	b = NULL;
	result = malloc(sizeof(char));
	if (result == 0)
		return (0);
	result[0] = '\0';
	init_stack(argc, argv, &a);
	push_swap(&a, &b, &result);
	return (0);
}
