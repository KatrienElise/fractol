/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/01 08:34:56 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void square(t_fractol *fract)
{
    /* fract->temp = (fract->a * fract->a) - (fract->b * fract->b);
     fract->b = 2.0 * fract->a * fract->b;
     fract->a = fract->temp;
     */
    if (fract->name == 1)
     {
          fract->tmp = fract->z_r;
         // number between 0.3 and 2
          fract->z_r = fract->z_r * fract->z_r - \
		     fract->z_i * fract->z_i - fract->change_jul + (fract->c_r / fract->winw);
	     fract->z_i = 2 * fract->z_i * fract->tmp + (fract->c_i / fract->winh);
     }
     
     else if (fract->name == 2)
     {
          fract->tmp = fract->z_r;
          fract->z_r = fract->z_r * fract->z_r - \
		     fract->z_i * fract->z_i + fract->c_r;
	     fract->z_i = 2 * fract->z_i * fract->tmp + fract->c_i;
     }

     else if (fract->name == 3)
     {
         // fract->tmp = fract->z_r;
          fract->tmp = fract->z_r * fract->z_r - fract->z_i * fract->z_i + fract->c_r;
        // fract->z_r = fract->z_r * fract->z_r - \
		//     fract->z_i * fract->z_i + fract->c_r;
	     fract->z_i = fabs(2 * fract->z_i * fract->tmp) + fract->c_i;
		fract->z_r = fract->tmp;
     }

     
}

void  magnitude(t_fractol *fract)
{
    fract->magni = fract->z_r * fract->z_r + 
     fract->z_i * fract->z_i;
}

void ft_calc_zero(t_fractol *fract)
{
    // fract->name = 0;
     fract->it_max = 0;
     fract->it = 0;
     fract->color.nb = 0;
     fract->color.nb2 = 0;
     fract->quit_mouse = 0;
     fract->move_hor = 0;
     fract->move_vert = 0;
     fract->put_index = 0;
     fract->shift = 0;
     fract->color.c = 0;
     fract->color.x = 0;
     fract->zoom = 0; // the bigger the number the bigger the fract
     fract->y = 0;
     fract->x = 0;
	fract->x1 = 0; // these numbers decide where in the window the fract comes
	fract->y1 = 0;
     fract->c_r = 0;
	fract->z_i = 0;
	fract->z_r = 0;
	fract->c_i = 0;
     fract->j_mouse = 0;
	fract->infi = 0;
     fract->magni = 0;
}
void calc_winw_winh(int ac, char **str, t_fractol *fract)
{
     if (ac == 4)
     {
         if (ft_isdigit_string(str[2]) == 1 && ft_isdigit_string(str[3]) == 1)
         {
            fract->winw = ft_atoi(str[2]);
            fract->winh = ft_atoi(str[3]);
         }
         else
          error(fract, 2);
     }
    else
    {
        fract->winw = 800;
        fract->winh = 800;
    }
}