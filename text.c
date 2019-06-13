/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/01 10:51:43 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_put_text(t_fractol *fract)
{
    mlx_string_put(fract->mlx, fract->win, 10, 10, WHITE, "katrien");
    if (fract->name == 1)
        mlx_string_put(fract->mlx, fract->win, (fract->winw / 3), 10, \
            WHITE, "julia");
    else if (fract->name == 2)
        mlx_string_put(fract->mlx, fract->win, (fract->winw / 3), 10, \
            WHITE, "mandelbrot");
    else
        mlx_string_put(fract->mlx, fract->win, (fract->winw / 3), 10, \
            WHITE, "burningship");
}

void    ft_text_index(t_fractol *fract)
{
    mlx_string_put(fract->mlx, fract->win, 10, 30, \
        WHITE, "q        = quit mouse julia");
    mlx_string_put(fract->mlx, fract->win, 10, 45, \
        WHITE, "m, j, u  = change fractal");
    mlx_string_put(fract->mlx, fract->win, 10, 65, \
        WHITE, "s        = shift to julia change");
    mlx_string_put(fract->mlx, fract->win, 10, 85, \
        WHITE, "c        = change color unstable");
    mlx_string_put(fract->mlx, fract->win, 10, 105, \
        WHITE, "x        = change color stable");
    mlx_string_put(fract->mlx, fract->win, 10, 125, \
        WHITE, "+, -     = changer s, c, x");
    mlx_string_put(fract->mlx, fract->win, 10, 145, \
        WHITE, "spatie   = reset");
    mlx_string_put(fract->mlx, fract->win, 10, 165, \
        WHITE, "o, i     = change iteratioins");
    mlx_string_put(fract->mlx, fract->win, 10, 185, \
        WHITE, "esc      = quit program");
}

void	put_pixel_to_img(t_fractol *fract, int x, int y, int color)
{
      ft_memcpy(&fract->data_addr[(4 * y * fract->winw) + (4 * x)], &color, 4);
}
