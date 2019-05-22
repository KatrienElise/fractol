/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prime_check.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 14:51:16 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/05 14:55:18 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_prime_check(int nb)
{
	int c;

	c = 2;
	while (c <= (nb - 1))
	{
		if (nb % c == 0)
			return (0);
		c++;
	}
	if (c == nb)
		return (1);
	return (0);
}
