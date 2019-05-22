/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 12:49:04 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/03 18:09:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *temp;

	temp = *alst;
	if (temp != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		free(temp);
		*alst = NULL;
	}
}
