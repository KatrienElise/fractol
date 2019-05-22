/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 18:07:08 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/04 08:36:03 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;

	i = 0;
	source = (unsigned char*)src;
	while (i < n)
	{
		if (source[i] == (unsigned char)c)
			return ((void*)&source[i]);
		i++;
	}
	return (NULL);
}
