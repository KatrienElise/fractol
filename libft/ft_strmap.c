/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 13:06:00 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/03 16:21:29 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fresh;
	int		len;

	i = 0;
	len = ft_strlen((char*)s);
	fresh = (char*)ft_memalloc(len + 1);
	if (!fresh)
		return (NULL);
	while (s[i])
	{
		fresh[i] = f((char)s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
