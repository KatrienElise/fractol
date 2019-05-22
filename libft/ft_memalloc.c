/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 13:17:51 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/18 13:44:39 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *res;

	res = malloc(sizeof(void) * size);
	if (res)
	{
		ft_bzero(res, size);
		return (res);
	}
	else
		return (NULL);
}
