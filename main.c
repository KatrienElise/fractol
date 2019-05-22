/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*  main.c                                               :+:    :+:           */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 17:52:00 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     main(int ac, char **av)
{
    if (ac == 2)
      entry(av);
    else
      ft_putstr("Usage: /fractol \"mandelbrot\", \"julia\", \"unknown\"\n");
    return (0); 
}