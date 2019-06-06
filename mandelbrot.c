/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/06 13:09:29 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_mandelbrot_base(t_fractol *fract)
{
	if (!fract->it_max)
    	fract->it_max = 40;
	if (fract->zoom == 0)
		fract->zoom = 1.3; // the bigger the number the bigger the fract
	if (!fract->x1)
		fract->x1 = -0.7;
	if (!fract->y1)
		fract->y1 = 0; 
  fract->y = 0;
	fract->infi = 6;
	if (fract->color.nb != 0 || fract->color.stable != 0)
	{
		ft_get_color(fract);
		color_stable(fract);
	}
	else
	{
		fract->color.base = BLUE;
		fract->color.stable = BLACK;
	}	
}

static void  magnitude(t_fractol *fract)
{
    fract->magni = fract->z_r * fract->z_r + 
     fract->z_i * fract->z_i;
}

static void    ft_calc_mandel(t_fractol *fract)
{

  	fract->c_r = (fract->x - fract->winw / 2) / 
		( 0.25 * fract->zoom * fract->winw) + fract->x1;
	fract->c_i = (fract->y - fract->winh / 2) / 
		( 0.25 * fract->zoom * fract->winh) + fract->y1;
	fract->z_r = fract->c_r;
	fract->z_i = fract->c_i;
	fract->it = 0;
	magnitude(fract);
	while (fabs(fract->z_r + fract->z_i) < fract->infi && fract->it < fract->it_max)
	{
      fract->tmp = fract->z_r;
      fract->z_r = fract->z_r * fract->z_r - \
		     fract->z_i * fract->z_i + fract->c_r;
	    fract->z_i = 2 * fract->z_i * fract->tmp + fract->c_i;
		fract->it++;
	}
	if (fract->it == fract->it_max)
		put_pixel_to_img(fract, fract->x, fract->y, fract->color.stable);
	else
		put_pixel_to_img(fract, fract->x, fract->y, \
			(fract->color.base * (fract->it)));
}

void    mandelbrot(t_fractol *fract)
{
	fract->x = 0;
	while (fract->y < fract->winh)
	{
		fract->x = 0;
		while (fract->x < fract->winw)
		{
			ft_calc_mandel(fract);
			fract->x++;
		}
		fract->y++;
    }
}

//thread join asks to wait on the curernt thread untill this thread is finished
