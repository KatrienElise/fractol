/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 17:52:00 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_julia_base(t_fractol *fract)
{
    fract->color = PINK;
    fract->it_max = 50;
    /*fract->x1 = -2.0
    fract->y1 = -1.9
    fract->c_r = 0.285
    fract->c_i = 0.01
    */
}

void    ft_calc_julia(t_fractol *fract)
{
    int x;
    int y;

    x = 400;
    y = 1;
    while (x < WINW && y < WINH) // een if statement en fract->if < fract->it_max
    {
        if (fract->it < fract->it_max)
            fract->color = fract->color * fract->it;
        else if (fract->it == fract->it_max)
        {
            fract->it = 0;
            fract->color = BLACK;
        }
        put_pixel_to_img(fract, x, y, fract->color);
        x--;
        y++;
        //fract->it = fract->it + 500;
    }
}