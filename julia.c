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

int		mouse_julia(int x, int y, t_fractol *fract)
{
    printf("loc x: %d, loc y: %d\n", x, y);
    /*
	//if (fract->name == 1 && fract->j_mouse == 1)
	//{
		fract->c_r = x * 2;
		fract->c_i = y * 2 - 800;
		ft_fract_set(fract);
	//}
    */
   //if (frac->stop == 0)
    ft_bzero(fract->data_addr, (fract->winw * fract->winh) * 4);
	fract->c_r = (x - fract->winw / 2)
			/ (2 * fract->zoom * fract->winw) + fract->x1;
	//if (frac->stop == 0)
	fract->c_i = (y - fract->winh / 2)
			/ (2 * fract->zoom * fract->winh) + fract->y1;
	return (0);
}

void    ft_julia_base(t_fractol *fract)
{
    fract->it_max = 70;
	fract->zoom = 1.3; // the bigger the number the bigger the fract
	fract->x1 = 0; // these numbers decide where in the window the fract comes
	fract->y1 = 0; //
    fract->y = 0;
    if (fract->j_mouse == 0)
    {
        fract->c_r = 0.285;
        fract->c_i = 0.08;
    }
	fract->infi = 4;
	ft_get_color(fract);
	//fract->color = BLUE;
}

void    ft_calc_julia(t_fractol *fract)
{
	//below: the / 0.25, the bigger the number the bigger the fract in the wind. 
    fract->z_r = (fract->x - fract->winw / 2) / 
		( 0.25 * fract->zoom * fract->winw) + fract->x1; // brengt 0,0 naar midden?
	fract->z_i = (fract->y - fract->winh / 2) / 
		( 0.25 * fract->zoom * fract->winh) + fract->y1;
	//fract->z_r = 0;
	//fract->z_i = 0;
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

void    julia(t_fractol *fract)
{
    fract->x = 0;
	fract->temp = fract->x;
	//printf("winw: %d, winh: %d\n", fract->winw, fract->winh);
	//test_print_values(fract);
	while (fract->y < fract->winh)
	{
		fract->x = fract->tmp;
		while (fract->x < fract->winw)
		{
			ft_calc_julia(fract);
			fract->x++;
		}
		fract->y++;
    }
}