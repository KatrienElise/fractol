/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/01 08:49:30 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     main(int ac, char **av)
{
    if (ac == 2 || ac == 4)
      entry(av, ac);
    else
      ft_putstr("Usage: /fractol \"mandelbrot\", \"julia\"");
      ft_putstr(" \"burningship\n");
      ft_putstr("option: winwith winheight\n");
    return (0); 
}
