/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*  main.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 17:52:00 by kblum         ########   odam.nl         */
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