/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 19:19:43 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/05 14:38:13 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *list)
{
	int len;

	len = 0;
	if (list)
	{
		while (list)
		{
			list = list->next;
			len++;
		}
		return (len);
	}
	else
		return (0);
	return (len);
}
