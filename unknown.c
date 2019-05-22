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

void    ft_unknown_base(t_fractol *fract)
{
    fract->it_max = 30;
	fract->zoom = 300;
	fract->x1 = -2.05;
	fract->y1 = -1.3; 
	fract->color = LIGHT_BLUE;
    fract->y = 0;
}

void    ft_calc_unknown(t_fractol *fract)
{
    fract->c_r = fract->x / fract->zoom + fract->x1; // brengt 0,0 naar midden?
	fract->c_i = fract->y / fract->zoom + fract->y1;
	fract->z_r = 0;
	fract->z_i = 0;
	fract->it = 0;
	while (fract->z_r * fract->z_r + fract->z_i *
			fract->z_i < 4 && fract->it < fract->it_max) // magni berekenen, 
            // gaat het naar infiniti of niet. Eerste deel is magni,
            // als magni kleiner is dan ,1,2,3,4 hoe groter het nummer hoe meer fract.
	{
		fract->tmp = fract->z_r;
		fract->z_r = fract->z_r * fract->z_r -
			fract->z_i * fract->z_i + fract->c_r;// square berekening
		fract->z_i = 2 * fract->z_i * fract->tmp + fract->c_i; // suare berekening en add?
		fract->it++;
	}
	if (fract->it == fract->it_max)
		put_pixel_to_img(fract, fract->x, fract->y, BLACK);
	else
		put_pixel_to_img(fract, fract->x, fract->y, (fract->color * fract->it));
}

void    unknown(t_fractol *fract)
{
    ft_putendl("unknwon:");
	fract->x = 0;
	fract->temp = fract->x;
	while (fract->y < WINH)
	{
		fract->x = fract->tmp;
		while (fract->x < WINW)
		{
			ft_calc_unknown(fract);
			fract->x++;
		}
		fract->y++;
    }
}