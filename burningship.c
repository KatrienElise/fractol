/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   burningship.c                                          :+:    :+:        */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/30 13:52:02 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_burningship_base(t_fractol *fract)
{
    fract->it_max = 30;
	fract->zoom = 1.3;
	fract->x1 = -0.7;
	fract->y1 = 0; 
	fract->color.base = LIGHT_BLUE;
    fract->y = 0;
	fract->infi = 4; //hoe groter infi hoe meer detai. 
}

void    ft_calc_burningship(t_fractol *fract)
{
	fract->c_r = (fract->x - fract->winw / 2) / 
		( 0.25 * fract->zoom * fract->winw) + fract->x1; // brengt 0,0 naar midden?
	fract->c_i = (fract->y - fract->winh / 2) / 
		( 0.25 * fract->zoom * fract->winh) + fract->y1;
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
		put_pixel_to_img(fract, fract->x, fract->y, BLACK);
	else
		put_pixel_to_img(fract, fract->x, fract->y, (fract->color.base * fract->it));
}

void    burningship(t_fractol *fract)
{
    ft_putendl("unknwon:");
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