/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstpushback.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 08:36:49 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/01 11:07:39 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **lst, void const *content, size_t content_size)
{
	t_list *temp;

	if (!lst || !*lst)
		*lst = ft_lstnew(content, content_size);
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = ft_lstnew(content, content_size);
	}
}
