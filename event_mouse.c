/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_mouse.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/01 10:47:41 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_julia(int x, int y, t_fractol *fract)
{
    printf("loc x: %d, loc y: %d\n", x, y);
    
	if (fract->name == 1 && fract->j_mouse == 1)
	{
		fract->c_r = x * 1.5;
		fract->c_i = y * 2 - 800;
		ft_fract_set(fract);
	}
    
   //if (frac->stop == 0)
    //ft_bzero(fract->data_addr, (fract->winw * fract->winh) * 4);
	//fract->c_r = (x - fract->winw / 2)
	//		/ (2 * fract->zoom * fract->winw) + fract->x1;
	//if (frac->stop == 0)
	//fract->c_i = (y - fract->winh / 2)
	//		/ (2 * fract->zoom * fract->winh) + fract->y1;
	return (0);
}

void    ft_in_zoom(int x, int y , t_fractol *fract)
{
   // x = 0;
    //y = 0;
    // x and y have to become the new center points. 
    printf("ZOOM: it_max is: %d, fract->x1: %f, fract->zoom: %f\n", fract->it_max, fract->x1, fract->zoom);
    //fract->x1 = (x / fract->zoom + fract->x1) - (x / (fract->zoom * 1.3));
	//fract->y1 = (y / fract->zoom + fract->y1) - (y / (fract->zoom * 1.3));

	//fract->x1 += (x - fract->winw / 2) * 0.05 / fract->zoom;
    //fract->y1 += (y - fract->winh / 2) * 0.05 / fract->zoom;

	fract->x1 += (x - fract->winw / 2) / fract->winw / fract->zoom;
    fract->y1 += (y - fract->winh / 2) / fract->winh / fract->zoom;
	//fract->zoom = fract->zoom + 0.3;    
	fract->zoom = fract->zoom + 0.5;
	fract->it_max++;
}

void    ft_out_zoom(int x, int y , t_fractol *fract)
{
    fract->x = (x / fract->zoom + fract->x1)  - (x / (fract->zoom / 1.3));
	fract->y = (y / fract->zoom + fract->y1) - (y / (fract->zoom / 1.3));
	fract->zoom = fract->zoom - 0.5;
	fract->it_max--;
}

int    event_mouse_move(int x, int y, t_fractol *fract)
{
    if (fract->name == 1 && fract->quit_mouse == 0)
    {
        fract->j_mouse = 1;
        mouse_julia(x, y, fract);
        ft_bzero(fract->data_addr, (fract->winw * fract->winh) * 4);
        ft_fract_base(fract);
    }
    return (0);
}

int    event_mouse(int mousecode, int x, int y, t_fractol *fract)
{
    if (mousecode == 1 || mousecode == 5)
        ft_in_zoom(x, y, fract);
    else if (mousecode == 2 || mousecode == 4)
        ft_out_zoom(x, y, fract);
    //ft_bzero(fract->data_addr, (fract->winw * fract->winh) * 4);
    ft_fract_base(fract);
    return (0);
}