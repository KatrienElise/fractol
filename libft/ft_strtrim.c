/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 17:27:04 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/03 16:22:52 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		x;
	char	*fresh;
	int		len;
	char	*temp;

	temp = (char*)s;
	i = 0;
	x = 0;
	len = 0;
	len = ft_strlen(temp) - 1;
	while (temp[i] == ' ' || temp[i] == '\n' || temp[i] == '\t')
		i++;
	while (temp[len] == ' ' || temp[len] == '\n' || temp[len] == '\t')
		len--;
	len++;
	if (len - i > 0)
		return (fresh = ft_strsub(temp, i, len - i));
	else
	{
		fresh = (char*)malloc(sizeof(char) * 1);
		fresh[x] = '\0';
	}
	return (fresh);
}
