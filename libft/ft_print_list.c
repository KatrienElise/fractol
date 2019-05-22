/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_list.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 12:17:06 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/05 14:33:23 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->content);
		ft_putchar('\n');
		list = list->next;
	}
}
