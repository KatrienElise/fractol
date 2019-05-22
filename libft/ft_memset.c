/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 11:41:24 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/01 15:37:27 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*mem;

	mem = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		mem[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
