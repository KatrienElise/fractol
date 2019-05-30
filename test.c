/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/30 13:49:29 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(t_fractol *fract, int x, int y, int color)
{
	//while (x < WINW && y < WINH)
   // {
      ft_memcpy(&fract->data_addr[(4 * y * fract->winw) + (4 * x)], &color, 4);
      //  x++;
      //  y++;
  // }
   // mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}

void  test_print_values(t_fractol *fract)
{
   printf("PRINT: it_max: %d\nzoom: %f\nx1: %f\ny1: %f\n", fract->it_max, \
   fract->zoom, fract->x1, fract->y1);
   printf("PRINT: y: %d\nx: %d\ninfi: %d\n", fract->y, fract->x, \
   fract->infi);
   printf("PRINT: c_r: %fc_i: %f\n magni: %f\nz_r: %f\nz_i: %f\nzit_max: %d\n", \
   fract->c_r, fract->c_r, fract->magni, fract->z_r, fract->z_i, fract->it_max);
}