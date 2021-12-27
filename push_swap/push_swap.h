/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:11:01 by vjose             #+#    #+#             */
/*   Updated: 2021/11/17 17:11:01 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				flag;
	struct s_list	*next;
}	t_list;

//stack functions
void	sa(t_list **a, char **result);
void	sb(t_list **b, char **result);
void	pa(t_list **a, t_list **b, char **result);
void	pb(t_list **b, t_list **a, char **result);
void	ra(t_list **a, char **result);
void	rra(t_list **a, char **result);
void	rb(t_list **b, char **result);
void	rrb(t_list **b, char **result);

//list functions
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstprelast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

//libft functions
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void	*dest, const void	*src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	ft_free(char **tab);

//main algorithm
void	push_swap(t_list **a, t_list **b, char **result);
void	init_stack(int argc, char **argv, t_list **a);
int		check_arg(t_list **a, char *arg);
int		find_pivot(t_list *list, int index, int del);
void	sort_small_stack(t_list **a, t_list **b, char **result);
void	sort_small_a(t_list **a, char **result);
void	sort_small_b(t_list **b, char **result);
int		find_min(t_list *a);
void	place_last_elem(t_list **a, int min, char **result);
void	a_to_b(t_list **a, t_list **b, char **result);
void	b_to_a(t_list **b, t_list **a, char **result);
void	delete(char **result);
void	free_stack(t_list *a);

#endif