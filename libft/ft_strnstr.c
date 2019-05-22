/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 18:21:07 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/03 15:59:25 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t count;

	i = 0;
	j = 0;
	if (!(needle[i]))
		return ((char*)&haystack[0]);
	while (haystack[i] && ((size_t)i < len))
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			count = i;
			while (haystack[count] == needle[j] && needle[j] && count < len)
			{
				j++;
				count++;
				if (!(needle[j]))
					return ((char*)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
