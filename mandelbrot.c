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

void    ft_mandelbrot_base(t_fractol *fract)
{
    fract->it_max = 70;
	fract->zoom = 1.3; // the bigger the number the bigger the fract
	fract->x1 = -0.7; // these numbers decide where in the window the fract comes
	fract->y1 = 0; //
    fract->y = 0;
	fract->infi = 4;
	fract->color = BLUE;
}

void    ft_calc_mandel(t_fractol *fract)
{
	//below: the / 0.25, the bigger the number the bigger the fract in the wind. 
    fract->c_r = (fract->x - fract->winw / 2) / 
		( 0.25 * fract->zoom * fract->winw) + fract->x1; // brengt 0,0 naar midden?
	fract->c_i = (fract->y - fract->winh / 2) / 
		( 0.25 * fract->zoom * fract->winh) + fract->y1;
	fract->z_r = 0;
	fract->z_i = 0;
	fract->it = 0;
	magnitude(fract);
	while (fract->magni < fract->infi && fract->it < fract->it_max) // magni berekenen, 
            // gaat het naar infiniti of niet. 
	{
		square(fract);
		fract->it++;
		magnitude(fract);
	}
	if (fract->it == fract->it_max)
		put_pixel_to_img(fract, fract->x, fract->y, BLACK);
	else
		put_pixel_to_img(fract, fract->x, fract->y, (fract->color * fract->it));
}

void    mandelbrot(t_fractol *fract)
{
    fract->x = 0;
	fract->temp = fract->x;
	while (fract->y < fract->winh)
	{
		fract->x = fract->tmp;
		while (fract->x < fract->winw)
		{
			ft_calc_mandel(fract);
			fract->x++;
		}
		fract->y++;
    }
}