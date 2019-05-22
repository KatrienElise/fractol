/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 12:04:06 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/01 15:44:05 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *fresh;

	fresh = (char*)malloc(sizeof(char) * size + 1);
	if (fresh)
	{
		ft_bzero(fresh, size + 1);
		return (fresh);
	}
	else
		return (NULL);
}
