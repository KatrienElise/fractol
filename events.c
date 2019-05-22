/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 17:52:00 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int     event_key_change(int keycode, t_fractol *fract)
{
    if (keycode == KEY_J)
        fract->name = 1;
     else if (keycode == KEY_M)
        fract->name = 2;
     else if (keycode == KEY_U)
        fract->name = 3;
    ft_bzero(fract->data_addr, (fract->winw * fract->winh) * 4);
    ft_base_func(fract);
    return (0);
}

int    event_key(int keycode, t_fractol *fract)
{
    if (keycode == KEY_ESC)
        exit_program(fract);
    else if (keycode == KEY_SPATIE)
        fract->infi = fract->infi -2;
    else if (keycode == KEY_T)
        fract->it = 2;
    else if (keycode == KEY_I)
        fract->infi = fract->infi++; // change the size
    else if (keycode == KEY_J || keycode == KEY_M || keycode == KEY_U)
        event_key_change(keycode, fract); // change between fracts
    //mlx_clear_window(fract->mlx, fract->win);
    else
        fract->no_event = 1;
    if (fract->no_event != 1)
        ft_base_func(fract);
    return (0);
}

int    event_mouse(int mousecode, int x, int y, t_fractol *fract)
{
    // in unknown word de gele lijn geheel overgetekent door de fractol.
    //toevoegen van mouse event, die de waardes verandert van x1, y1, zoomn en it_max
    //dan kan die alleen niet daarna weer eerst naar de base gaan.
    if (mousecode == 1)
    {
        ft_putendl("pressed left mouse button");
        while (x < fract->winw && y < fract->winh && y > 0 && x > 0)
        {
            put_pixel_to_img(fract, x, y, ORANGE);
            //x++;
            y++;
        }
    }
    ft_base_func(fract);
    return (0);
}