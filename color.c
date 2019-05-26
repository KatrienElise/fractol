/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                          :+:    :+:         */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 17:52:00 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    ft_get_color(t_fractol *fract)
{
    if (fract->color_nb == 0)
    {
        fract->color = BLUE;
        //fract->color_max = BLACK;
    }
    if (fract->color_nb == 1)
    {
        fract->color = DARK_GREEN;
        //fract->color_max = LIGHT_GREEN;    
    }
    
}