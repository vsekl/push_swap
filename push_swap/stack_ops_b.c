/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:48:09 by vjose             #+#    #+#             */
/*   Updated: 2021/12/14 16:02:31 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **b, t_list **a, char **result)
{
	t_list	*tmp;
	char	*buf;

	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	buf = ft_strjoin(*result, "1");
	free(*result);
	*result = buf;
}

void	rb(t_list **b, char **result)
{
	t_list	*tmp;
	t_list	*last;
	char	*buf;

	if ((*b)->next == NULL)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = NULL;
	last = ft_lstlast(*b);
	last->next = tmp;
	buf = ft_strjoin(*result, "4");
	free(*result);
	*result = buf;
}

void	sb(t_list **b, char **result)
{
	int		tmp;
	char	*buf;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
	buf = ft_strjoin(*result, "6");
	free(*result);
	*result = buf;
}

void	rrb(t_list **b, char **result)
{
	t_list	*tmp;
	t_list	*prelast;
	char	*buf;

	if ((*b)->next == NULL)
		return ;
	tmp = *b;
	prelast = ft_lstprelast(*b);
	*b = prelast->next;
	prelast->next->next = tmp;
	prelast->next = NULL;
	buf = ft_strjoin(*result, "7");
	free(*result);
	*result = buf;
}
