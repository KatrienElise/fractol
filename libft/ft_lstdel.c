/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 13:08:54 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/04 19:42:09 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	temp = *alst;
	while ((*alst)->next != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(temp);
		temp = *alst;
	}
	del((*alst)->content, (*alst)->content_size);
	*alst = (*alst)->next;
	free(temp);
	*alst = NULL;
}
