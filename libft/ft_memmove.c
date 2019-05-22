/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 11:11:29 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/04 10:51:57 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_revcpy(unsigned char *dest, unsigned char *source, size_t n)
{
	n--;
	while (n > 0)
	{
		dest[n] = source[n];
		n--;
	}
	dest[n] = source[n];
}

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned char		*source;

	i = 0;
	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (n > (size_t)(dest) - (size_t)(source))
	{
		ft_revcpy(dest, source, n);
		return (dst);
	}
	return (ft_memcpy(dest, src, n));
}
