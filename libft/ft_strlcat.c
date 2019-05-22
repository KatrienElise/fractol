/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:52:54 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/03 15:46:16 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t length;
	size_t i;

	length = (unsigned)ft_strlen(dst);
	i = 0;
	if (length >= size)
		return (ft_strlen((char*)src) + size);
	while (src[i] && ((length + i) < (size - 1)))
	{
		dst[length + i] = src[i];
		i++;
	}
	dst[length + i] = '\0';
	return (length + ft_strlen((char*)src));
}
