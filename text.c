/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text.c                                          :+:    :+:               */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 17:52:00 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_put_text(t_fractol *fract)
{
    mlx_string_put(fract->mlx, fract->win, 10, 10, RED, "katrien");
    if (fract->name == 1)
        mlx_string_put(fract->mlx, fract->win, 150, 10, RED, "julia");
    else if (fract->name == 2)
        mlx_string_put(fract->mlx, fract->win, 150, 10, RED, "mandelbrot");
    else
        mlx_string_put(fract->mlx, fract->win, 150, 10, RED, "unknown");
}