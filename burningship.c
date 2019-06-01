/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   burningship.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/01 08:45:42 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_burningship_base(t_fractol *fract)
{
	if(!fract->it_max)
    	fract->it_max = 30;
	if(!fract->zoom)
		fract->zoom = 1.3;
	if (!fract->x1)
		fract->x1 = -0.5;
	if (!fract->y1)
		fract->y1 = -0.2; 
    fract->y = 0;
	fract->infi = 3; //hoe groter infi hoe meer detai. 
	ft_get_color(fract);
	color_stable(fract);
}

void    ft_calc_burningship(t_fractol *fract)
{
	fract->c_r = (fract->x - fract->winw / 2) / 
		( 0.5 * fract->zoom * fract->winw) + fract->x1; // brengt 0,0 naar midden?
	fract->c_i = (fract->y - fract->winh / 2) / 
		( 0.5 * fract->zoom * fract->winh) + fract->y1;
	fract->z_r = 0;
	fract->z_i = 0;
	fract->it = 0;
	magnitude(fract);
	while (fract->magni < fract->infi && fract->it < fract->it_max)
	{
		square(fract);
		fract->it++;
		magnitude(fract);
	}
	if (fract->it == fract->it_max)
		put_pixel_to_img(fract, fract->x, fract->y, fract->color.stable);
	else
		put_pixel_to_img(fract, fract->x, fract->y, (fract->color.base * fract->it));
}

void    burningship(t_fractol *fract)
{
	fract->x = 0;
	fract->tmp = fract->x;
	while (fract->y < fract->winh)
	{
		fract->x = fract->tmp;
		while (fract->x < fract->winw)
		{
			ft_calc_burningship(fract);
			fract->x++;
		}
		fract->y++;
    }
}