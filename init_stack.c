/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:59:05 by vjose             #+#    #+#             */
/*   Updated: 2021/11/29 18:59:05 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_unique(t_list *a)
{
	t_list	*tmp;
	t_list	*start;

	start = a;
	while (a != NULL)
	{
		tmp = start;
		while (tmp != a)
		{
			if (tmp->content == a->content)
			{
				write(1, "Error\n", 6);
				free_stack(start);
				exit(0);
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
}

static void	check_issorted(t_list *a)
{
	if (a == NULL)
		exit(0);
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return ;
		a = a->next;
	}
	free_stack(a);
	exit(0);
}

void	init_stack(int argc, char **argv, t_list **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{	
		if (check_arg(a, argv[i]) == 0)
		{
			write(1, "Error\n", 6);
			free_stack(*a);
			exit(0);
		}
		i++;
	}
	check_unique(*a);
	check_issorted(*a);
}
