/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:48:18 by vjose             #+#    #+#             */
/*   Updated: 2021/12/14 15:48:18 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b, char **result)
{
	t_list	*tmp;
	char	*buf;

	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp;
	buf = ft_strjoin(*result, "0");
	free(*result);
	*result = buf;
}

void	ra(t_list **a, char **result)
{
	t_list	*tmp;
	t_list	*last;
	char	*buf;

	if ((*a)->next == NULL)
		return ;
	tmp = *a;
	*a = tmp->next;
	tmp->next = NULL;
	last = ft_lstlast(*a);
	last->next = tmp;
	buf = ft_strjoin(*result, "2");
	free(*result);
	*result = buf;
}

void	rra(t_list **a, char **result)
{
	t_list	*tmp;
	t_list	*prelast;
	char	*buf;

	if ((*a)->next == NULL)
		return ;
	tmp = *a;
	prelast = ft_lstprelast(*a);
	*a = prelast->next;
	prelast->next->next = tmp;
	prelast->next = NULL;
	buf = ft_strjoin(*result, "3");
	free(*result);
	*result = buf;
}

void	sa(t_list **a, char **result)
{
	int		tmp;
	char	*buf;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	buf = ft_strjoin(*result, "5");
	free(*result);
	*result = buf;
}
