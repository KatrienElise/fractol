/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/30 17:02:03 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     event_key_change(int keycode, t_fractol *fract)
{
    ft_calc_zero(fract);
    if (keycode == KEY_J)
        fract->name = 1;
     else if (keycode == KEY_M)
        fract->name = 2;
     else if (keycode == KEY_U)
        fract->name = 3;
    ft_bzero(fract->data_addr, (fract->winw * fract->winh) * 4);
    ft_fract_base(fract);
    return (0);
}

int    event_key(int keycode, t_fractol *fract)
{
    if (keycode == KEY_ESC)
        exit_program(fract);
    /*else if (keycode == KEY_SPATIE) change the infi & it_max
        fract->infi = fract->infi -2;
    else if (keycode == KEY_T)
        fract->it_max = 2;
        */
    else if (keycode == KEY_S)
    {
        if (fract->shift == 0)
            fract->shift = 1;
        else 
            fract->shift = 0;            
    }
    else if (keycode == KEY_C)
    {
        if (fract->color.c == 0)
            fract->color.c = 1;
        else 
            fract->color.c = 0;            
    }
    else if (keycode == KEY_X)
    {
        if (fract->color.x == 0)
            fract->color.x = 1;
        else 
            fract->color.x = 0;            
    }
    else if (keycode == KEY_PLUS && fract->shift == 1)
        fract->change_jul = fract->change_jul + 0.1;
    else if (keycode == KEY_MIN && fract->shift == 1)
        fract->change_jul = fract->change_jul - 0.1;
    else if (keycode == KEY_PLUS && fract->color.c == 1)
    {
        if (fract->color.nb < 11)
            fract->color.nb++;
    }
    else if (keycode == KEY_MIN && fract->color.c == 1)
    {
        if (fract->color.nb > 0)
            fract->color.nb--;
    }
    else if (keycode == KEY_PLUS && fract->color.x == 1)
    {
        if (fract->color.nb2 < 9)
            fract->color.nb2++;
        //color_stable(fract);
    }
    else if (keycode == KEY_MIN && fract->color.x == 1)
    {
        if (fract->color.nb2 > 0)
            fract->color.nb2--;
        //color_stable(fract);
    }
    else if (keycode == KEY_J || keycode == KEY_M || keycode == KEY_U)
        event_key_change(keycode, fract); // change between fracts
    //mlx_clear_window(fract->mlx, fract->win);
    else
        fract->no_event = 1;
    //if (fract->no_event != 1)
    //ft_bzero(fract->data_addr, (fract->winw * fract->winh) * 4);
    ft_fract_base(fract);
    return (0);
}

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