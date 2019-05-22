/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 14:27:22 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/03 16:22:05 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;
	int				len;

	i = 0;
	len = ft_strlen((char*)s);
	fresh = (char*)ft_memalloc(len + 1);
	if (!fresh)
		return (NULL);
	while (s[i])
	{
		fresh[i] = f(i, (char)s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
