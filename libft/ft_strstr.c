/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:43:36 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/03 15:59:10 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	if (!(needle[i]))
		return ((char*)&haystack[0]);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			count = i;
			while (haystack[count] == needle[j] && needle[j])
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
