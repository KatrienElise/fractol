/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/05 18:08:06 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_julia_base(t_fractol *fract)
{
	if (!fract->it_max)
    	fract->it_max = 30;
	if (fract->zoom == 0)
		fract->zoom = 1.3;
	if (!fract->x1)
		fract->x1 = 0;
	if (fract->y1)
		fract->y1 = 0;
    fract->y = 0;
    if (fract->j_mouse == 0)
    {
        fract->c_r = 0.285; //0.285
        fract->c_i = 0.08;
    }
	fract->infi = 4;
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

static void    ft_calc_julia(t_fractol *fract)
{ 
    fract->z_r = (fract->x - fract->winw / 2) / 
		( 0.25 * fract->zoom * fract->winw) + fract->x1;
	fract->z_i = (fract->y - fract->winh / 2) / 
		( 0.35 * fract->zoom * fract->winh) + fract->y1;
	fract->it = 0;
	magnitude(fract);
	while (fract->magni < fract->infi && fract->it < fract->it_max)
	{
		//square(fract);
		fract->tmp = fract->z_r;
        fract->z_r = fract->z_r * fract->z_r - \
			fract->z_i * fract->z_i - fract->change_jul + \
               (fract->c_r / fract->winw);
	    fract->z_i = 2 * fract->z_i * fract->tmp + (fract->c_i / fract->winh);
		fract->it++;
		magnitude(fract);
	}
	if (fract->it == fract->it_max)
		//put_pixel_to_img(fract, fract->x, fract->y, fract->color.stable);
		ft_memcpy(&fract->data_addr[(4 * fract->y * fract->winw) + (4 * fract->x)], &fract->color.stable, 4);
	else
		//ft_memcpy(&fract->data_addr[(4 * fract->y * fract->winw) + (4 * fract->x)], &(fract->color.base * fract->it), 4);
		put_pixel_to_img(fract, fract->x, fract->y, (fract->color.base * (fract->it)));
}

void    julia(t_fractol *fract)
{
    fract->x = 0;
	
	while (fract->y < fract->winh)
	{
		fract->x = 0;
		while (fract->x < fract->winw)
		{
			ft_calc_julia(fract);
			fract->x++;
		}
		fract->y++;
    }
}