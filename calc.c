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

void    square(t_fractol *fract)
{
    /* fract->temp = (fract->a * fract->a) - (fract->b * fract->b);
     fract->b = 2.0 * fract->a * fract->b;
     fract->a = fract->temp;
     */
     fract->tmp = fract->z_r;
     fract->z_r = fract->z_r * fract->z_r -
		fract->z_i * fract->z_i + fract->c_r;
	fract->z_i = 2 * fract->z_i * fract->tmp + fract->c_i;
}

void  magnitude(t_fractol *fract)
{
    fract->magni = fract->z_r * fract->z_r + 
     fract->z_i * fract->z_i;
}

void      add(t_fractol *fract)
{
     fract->a = fract->a + fract->ca;
     fract->b = fract->b + fract->cb;
}

void      calc_winw_winh(int ac, char **str, t_fractol *fract)
{
     if (ac == 4)
    {
        fract->winw = ft_atoi(str[2]);
        fract->winh = ft_atoi(str[3]);
    }
    else
    {
        fract->winw = 800;
        fract->winh = 800;
    }
}