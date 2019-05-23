/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*  main.c                                               :+:    :+:           */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/23 17:25:34 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     main(int ac, char **av)
{
    if (ac == 2 || ac == 4)
      entry(av, ac);
    else
      ft_putstr("Usage: /fractol \"mandelbrot\", \"julia\", \"unknown\",");
      ft_putstr(" option: winwith winheight\n");
    return (0); 
}
