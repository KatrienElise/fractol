/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 09:53:29 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/21 16:43:43 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	newlist = (t_list*)malloc(sizeof(t_list));
	if (newlist)
	{
		if (content == NULL)
		{
			newlist->content = NULL;
			newlist->content_size = 0;
			newlist->next = NULL;
		}
		else
		{
			newlist->content = malloc(content_size);
			if (!newlist->content)
				return (NULL);
			ft_memcpy(newlist->content, content, content_size);
			newlist->content_size = content_size;
			newlist->next = NULL;
		}
	}
	else
		return (NULL);
	return (newlist);
}
