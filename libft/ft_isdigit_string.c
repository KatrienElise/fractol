/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit_string.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/30 11:27:26 by kblum          #+#    #+#                */
/*   Updated: 2019/05/30 15:04:29 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_isdigit_string(char *str)
{
	int i;

	i = 0; 
	while (str[i])
	{
	
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);

			
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}
