/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_mouse.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/06 13:05:33 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		mouse_julia(int x, int y, t_fractol *fract)
{   
	if (fract->name == 1 && fract->j_mouse == 1)
	{
		fract->c_r = x * 2;
		fract->c_i = y * 2 - 800;
		ft_fract_set(fract);
	}
	return (0);
}

static void    ft_in_zoom(int x, int y , t_fractol *fract)
{
    int new_x;
    int new_y;

    new_x = x - (fract->winw * .5);
    new_y = y - (fract->winh * .5);
    fract->x1 += new_x / (fract->winw * .5) / fract->zoom;
    fract->y1 += new_y / (fract->winh * .5) / fract->zoom;
	fract->zoom *= 1.1;
	fract->it_max++;
}

static void    ft_out_zoom(int x, int y , t_fractol *fract)
{
    int new_x;
    int new_y;

    new_x = x - (fract->winw * .5);
    new_y = y - (fract->winh * .5);
    fract->x1 -= new_x / (fract->winw * .5) / fract->zoom;
    fract->y1 -= new_y / (fract->winh * .5) / fract->zoom;
	fract->zoom *= .9;
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
    ft_fract_base(fract);
    return (0);
}