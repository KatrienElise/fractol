/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sine.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/01 09:10:20 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_sine_base(t_fractol *fract)
{
	if (!fract->it_max)
    	fract->it_max = 100;
	if (fract->zoom == 0)
		fract->zoom = 1.3; // the bigger the number the bigger the fract
	fract->x1 = 0; // these numbers decide where in the window the fract comes
	fract->y1 = 0; //
    fract->y = 0;
	fract->infi = 4;
	ft_get_color(fract);
	color_stable(fract);
	//fract->color = BLUE;
}

void    ft_calc_sine(t_fractol *fract)
{
	double tem;

	fract->c_r = ((fract->z_r / fract->winw) * 5 - 2.5) / fract->zoom + fract->x1;
	fract->c_i = ((fract->z_i / fract->winh) * 5 - 2.5) / fract->zoom + fract->y1;
	//iteration = 0;
	fract->z_r = 0;
	fract->z_i = 0;
	while (fract->z_r * fract->z_r + fract->z_i * fract->z_i < 31.415926536 && (fract->it < fract->it_max))
	{
		tem = fract->z_r;

		fract->z_r = sin(fract->z_r) * cosh(fract->z_i) + fract->c_r;
		fract->z_i = cos(tem) * sinh(fract->z_i) + fract->c_i;
		fract->x = fract->z_r;
		fract->y = fract->z_i;
		fract->it++;
	}
	if (fract->it == fract->it_max)
		put_pixel_to_img(fract, fract->x, fract->y, fract->color.stable);
	else
		put_pixel_to_img(fract, fract->x, fract->y, (fract->color.base * (fract->it)));
}

void    sine(t_fractol *fract)
{
	while (fract->y < fract->winh)
	{
		fract->x = 0;
		while (fract->x < fract->winw)
		{
			ft_calc_sine(fract);
			fract->x++;
		}
		fract->y++;
    }
}