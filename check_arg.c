/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:24:35 by vjose             #+#    #+#             */
/*   Updated: 2021/12/14 22:26:39 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overflow(char *arg)
{
	long int	result;
	int			flag;

	flag = 1;
	result = 0;
	if (*arg == '-')
	{
		arg++;
		flag = -1;
	}
	while (*arg != '\0')
	{
		result = result * 10 + (*arg - '0');
		arg++;
	}
	if (result * flag > 2147483647 || result * flag < -2147483648)
		return (0);
	return (1);
}

static int	check_if_num(char **tab, int i, int j)
{
	while (tab[i][j] != '\0')
	{
		if (ft_isdigit(tab[i][j]) == 0)
			return (0);
		j++;
	}
	return (1);
}

int	check_arg(t_list **a, char *arg)
{
	int		i;
	int		j;
	char	**tab;
	int		num;

	i = 0;
	j = 0;
	tab = ft_split(arg, ' ');
	while (tab[i] != NULL)
	{
		if ((tab[i][j] == '+' || tab[i][j] == '-') && tab[i][j + 1] != '\0')
			j++;
		if (check_if_num(tab, i, j) == 0 || check_overflow(tab[i]) == 0)
		{	
			ft_free(tab);
			return (0);
		}
		num = ft_atoi(tab[i]);
		ft_lstadd_back(a, ft_lstnew(num));
		j = 0;
		i++;
	}
	ft_free(tab);
	return (1);
}
