/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_key.c                                           :+:    :+:         */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/30 17:02:03 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_in_zoom(int x, int y , t_fractol *fract)
{
    printf("ZOOM: it_max is: %d, fract->x1: %f, fract->zoom: %f\n", fract->it_max, fract->x1, fract->zoom);
    fract->x = (x / fract->zoom + fract->x1) - (x / (fract->zoom * 1.3));
	fract->y = (y / fract->zoom + fract->y1) - (y / (fract->zoom * 1.3));
    //fract->y += (y - fract->winh / 2) * 0.05 / fract->zoom;
	//fract->x += (x - fract->winw / 2) * 0.05 / fract->zoom;
	fract->zoom = fract->zoom + 0.3;    
	//fract->zoom /= 0.5;
	fract->it_max++;
}

void    ft_out_zoom(int x, int y , t_fractol *fract)
{
    fract->x = (x / fract->zoom + fract->x1)  - (x / (fract->zoom / 1.3));
	fract->y = (y / fract->zoom + fract->y1) - (y / (fract->zoom / 1.3));
	fract->zoom = fract->zoom - 0.5;
	//c=fract->it_max--;
}

int    event_mouse(int mousecode, int x, int y, t_fractol *fract)
{
   if (mousecode == 1 && fract->name == 1)
    {
        fract->j_mouse = 1;
        mouse_julia(x, y, fract);
    }
    if (mousecode == 1 || mousecode == 5)
        ft_in_zoom(x, y, fract);
    else if (mousecode == 2 || mousecode == 4)
        ft_out_zoom(x, y, fract);
    ft_bzero(fract->data_addr, (fract->winw * fract->winh) * 4);
    ft_fract_base(fract);
    return (0);
}