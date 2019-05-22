/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*  main.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 17:52:00 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    exit_program(t_fractol *fract)
{
    fract = NULL;
        //mlx_destroy_window(fract->mlx, fract->win);
        //mlx_destroy_image(fract->mlx, fract->img);
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
    //mlx_destroy_window(fract->mlx, fract->win);
    //mlx_destroy_image(fract->mlx, fract->img);
	exit(0);
}

