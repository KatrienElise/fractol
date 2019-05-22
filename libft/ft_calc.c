/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 19:45:19 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/05 15:08:33 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calc(int n1, char c, int n2)
{
	int res;

	res = 0;
	if (c == '-')
		return (n1 - n2);
	if (c == '+')
		return (n1 + n2);
	if (c == '/')
		return (n1 / n2);
	if (c == '*')
		return (n1 * n2);
	if (c == '%')
		return (n1 & n2);
	return (0);
}
