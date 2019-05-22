/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 18:56:32 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/03 16:23:25 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_index(int n)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n == 0)
		count++;
	while (n >= 1)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*fill_array(char *array_int, int n, int count)
{
	array_int[count] = '\0';
	count--;
	if (n < 0)
	{
		n = -n;
		array_int[0] = '-';
	}
	if (n == 0)
		array_int[count] = '0';
	while (n >= 1)
	{
		array_int[count] = ((n % 10) + '0');
		n = n / 10;
		count--;
	}
	return (array_int);
}

char		*ft_itoa(int n)
{
	char	*fresh;
	int		count;

	count = count_index(n);
	fresh = ft_strnew(count);
	if (!(fresh))
		return (NULL);
	if (n == -2147483648)
		fresh = ft_strcpy(fresh, "-2147483648");
	else
		fresh = fill_array(fresh, n, count);
	return (fresh);
}
