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
     if (fract->name == 2)
     {
          fract->z_r = fract->z_r * fract->z_r - \
		     fract->z_i * fract->z_i + fract->c_r;
	     fract->z_i = 2 * fract->z_i * fract->tmp + fract->c_i;
     }
     
     else if (fract->name == 1)
     {
          fract->z_r = fract->z_r * fract->z_r - \
		     fract->z_i * fract->z_i - 0.9 + (fract->c_r / fract->winw);
	     fract->z_i = 2 * fract->z_i * fract->tmp + (fract->c_i / fract->winh);
     }
     
}

void  magnitude(t_fractol *fract)
{
    fract->magni = fract->z_r * fract->z_r + 
     fract->z_i * fract->z_i;
}

void      ft_calc_zero(t_fractol *fract)
{
    fract->nb = 0;
    fract->it_max = 0;
	fract->zoom = 0; // the bigger the number the bigger the fract
	fract->x1 = 0; // these numbers decide where in the window the fract comes
	fract->y1 = 0; //
    fract->y = 0;
    fract->c_r = 0;
	fract->z_i = 0;
	fract->z_r = 0;
	fract->c_i = 0;
	fract->infi = 0;
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