/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:10:38 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/03 15:59:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int l;

	l = ft_strlen((char*)s);
	while (l >= 0)
	{
		if (s[l] == (unsigned char)c)
			return ((char*)&s[l]);
		l--;
	}
	return (NULL);
}
