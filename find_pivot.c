/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:50:24 by vjose             #+#    #+#             */
/*   Updated: 2021/12/14 19:38:30 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_next_node(t_list *smaller_than_pivot, \
							t_list *bigger_than_pivot, int index)
{
	int		len;

	len = index - ft_lstsize(smaller_than_pivot);
	if (len > 0)
	{
		free_stack(smaller_than_pivot);
		return (find_pivot(bigger_than_pivot, len, 1));
	}
	else
	{
		free_stack(bigger_than_pivot);
		return (find_pivot(smaller_than_pivot, index, 1));
	}
}

void	fill_sublists(t_list **smaller_than_pivot, t_list **bigger_than_pivot, \
					t_list **list, int pivot)
{
	if ((*list)->content > pivot)
		ft_lstadd_front(bigger_than_pivot, ft_lstnew((*list)->content));
	else if ((*list)->content < pivot)
		ft_lstadd_front(smaller_than_pivot, ft_lstnew((*list)->content));
	*list = (*list)->next;
}

int	find_pivot(t_list *list, int index, int del)
{	
	t_list	*smaller_than_pivot;
	t_list	*bigger_than_pivot;
	int		pivot;
	int		flag;
	t_list	*start;

	if (list->next == NULL)
	{
		pivot = list->content;
		free_stack(list);
		return (pivot);
	}
	smaller_than_pivot = NULL;
	bigger_than_pivot = NULL;
	pivot = list->content;
	flag = list->flag;
	start = list;
	while (list != NULL && list->flag == flag)
		fill_sublists(&smaller_than_pivot, &bigger_than_pivot, &list, pivot);
	ft_lstadd_back(&smaller_than_pivot, ft_lstnew(pivot));
	if (del == 1)
		free_stack(start);
	return (find_next_node(smaller_than_pivot, bigger_than_pivot, index));
}
