/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 15:57:49 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/03 16:23:04 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char *str, char c)
{
	int		x;
	int		count;

	x = 0;
	count = 0;
	while (str[x])
	{
		while (str[x] == c)
			x++;
		while (str[x] != c)
		{
			x++;
			if ((!str[x]) || str[x] == c)
			{
				count++;
				if (!str[x])
					return (count);
				x++;
			}
		}
	}
	return (count);
}

static int	plus(char *s, int i, int c)
{
	while (s[i] == c)
		i++;
	return (i);
}

static char	**ft_fill(char **copy, char const *s, char c, int max_y)
{
	int i;
	int j;
	int ci;

	i = 0;
	j = 0;
	ci = 0;
	while (s[i] && j < max_y)
	{
		i = plus((char*)s, i, c);
		ci = i;
		while (s[i] != c && s[i])
			i++;
		if ((i - ci) > 0)
		{
			copy[j] = ft_strsub(s, ci, i - ci);
			if (!copy[j])
				return (NULL);
			j++;
		}
	}
	copy[j] = (NULL);
	return (copy);
}

char		**ft_strsplit(char const *s, char c)
{
	int		max_y;
	char	**copy;

	max_y = ft_word_count((char*)s, c);
	copy = (char**)malloc(sizeof(char*) * (max_y + 1));
	if (!copy)
		return (NULL);
	copy = ft_fill(copy, s, c, max_y);
	if (!copy)
		return (NULL);
	return (copy);
}
