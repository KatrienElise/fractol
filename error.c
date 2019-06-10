/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/30 11:25:23 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    exit_program(t_fractol *fract)
{
    fract = NULL;
		exit(0);
}

void    error_no_struct(int d)
{
    if (d == 1)
        ft_putendl("error: allocating memory"); 
	exit(0);
}

void    error(t_fractol *fract, int d)
{
    fract = NULL;
    if (d == 1)
        ft_putendl("No right fractol name");
    else if (d == 2)
    {
        ft_putstr("Usage: /fractol \"mandelbrot\", \"julia\", \"unknown\",");
        ft_putstr(" option: winwith winheight\n");
    }
	exit(0);
}

