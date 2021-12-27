/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:52:52 by vjose             #+#    #+#             */
/*   Updated: 2021/12/14 22:10:00 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s != NULL)
	{
		if (start >= ft_strlen(s))
			return (ft_strdup("\0"));
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		str = ft_memcpy(str, s + start, len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	counter;
	int		flag;

	counter = 0;
	flag = 1;
	while (*s != 0)
	{
		if (*s == c)
			flag = 1;
		while (*s == c)
			s++;
		if (*s != 0 && flag == 1)
		{
			counter++;
			flag = 0;
		}
		while (*s != c && *s != 0)
			s++;
	}
	return (counter);
}

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	ft_fill_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i + j] != '\0' && s[i + j] != c)
			j++;
		if (j != 0)
		{
			tab[k] = ft_substr(s, i, j);
			if (tab[k] == NULL)
			{
				ft_free(tab);
				break ;
			}
			k++;
		}
		i = i + j;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	words_size;
	char	**tab;

	if (s == NULL)
		return (NULL);
	words_size = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (words_size + 1));
	if (tab == NULL)
		return (NULL);
	ft_fill_tab(tab, s, c);
	if (tab != NULL)
		tab[words_size] = NULL;
	return (tab);
}
