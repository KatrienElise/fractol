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
	fract->zoom = 300;
	fract->x1 = -2.05;
	fract->y1 = -1.3;
    fract->y = 0;
	fract->color = BLUE;
}

void    ft_calc_mandel(t_fractol *fract)
{
    fract->c_r = fract->x / fract->zoom + fract->x1; // brengt 0,0 naar midden?
	fract->c_i = fract->y / fract->zoom + fract->y1;
	fract->z_r = 0;
	fract->z_i = 0;
	fract->it = 0;
	while (fract->z_r * fract->z_r + fract->z_i *
			fract->z_i < 4 && fract->it < fract->it_max) // magni berekenen, 
            // gaat het naar infiniti of niet. 
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
       /* square(fract);
        add(fract);
        magnitude(fract);
        if (fract->magni > 2)
            break;
        fract->it++;
        }
        if (fract->it == fract->it_max)
            fract->color = GREEN;
        else if (fract->it < fract->it_max)
            fract->color = BLUE;
        else
            fract->color = YELLOW;
        put_pixel_to_img(fract, fract->x, fract->y, fract->color);
        fract->x++;  
        }
        fract->y++;
        */
    //mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);

void    mandelbrot(t_fractol *fract)
{
    fract->x = 0;
	fract->temp = fract->x;
	while (fract->y < WINH)
	{
		fract->x = fract->tmp;
		while (fract->x < WINW)
		{
			ft_calc_mandel(fract);
			fract->x++;
		}
		fract->y++;
    }
}