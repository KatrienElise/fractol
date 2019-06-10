/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_key.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/06 14:01:54 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int     event_change_fract(int keycode, t_fractol *fract)
{
	ft_calc_zero(fract);
    if (keycode == KEY_J)
        fract->name = 1;
     else if (keycode == KEY_M)
        fract->name = 2;
     else if (keycode == KEY_B)
        fract->name = 3;
    ft_bzero(fract->data_addr, (fract->winw * fract->winh) * 4);
    ft_fract_base(fract);
    return (0);
}

static int   event_shifts(int keycode, t_fractol *fract)
{
    if (keycode == KEY_PLUS && fract->shift == 1)
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
        if (fract->color.nb2 < 11)
            fract->color.nb2++;
    }
    else if (keycode == KEY_MIN && fract->color.x == 1)
    {
        if (fract->color.nb2 > 0)
            fract->color.nb2--;
    }
    return (0);
}
static int    event_key2(int keycode, t_fractol *fract)
{
    if (keycode == KEY_RIGHT)
        fract->x1 = fract->x1 - 0.08 / fract->zoom;
    else if (keycode == KEY_LEFT)
        fract->x1 = fract->x1 + 0.08 / fract->zoom;
    else if (keycode == KEY_DOWN)
        fract->y1 = fract->y1 - 0.08 / fract->zoom;
    else if (keycode == KEY_UP)
        fract->y1 = fract->y1 + 0.08 / fract->zoom;
    else if (keycode == KEY_I)
        fract->it_max = fract->it_max + 15;
    else if (keycode == KEY_O)
    {
        if (fract->it_max >= 15)
            fract->it_max = fract->it_max - 15;
    }
    else if (keycode == KEY_T)
    {
        if (fract->put_index == 0)
            fract->put_index = 1;
        else
            fract->put_index = 0;
    }
    else 
        return (1);
    return (0);
}

static void event_decider(int keycode, t_fractol *fract)
{
    if (keycode == KEY_S)
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
}

int         event_key(int keycode, t_fractol *fract)
{
    if (keycode == KEY_ESC)
        exit_program(fract);
    else if (keycode == KEY_Q && fract->name == 1)
    {
        if (fract->quit_mouse == 0)
            fract->quit_mouse = 1;
        else 
            fract->quit_mouse = 0;            
    }
    else if (keycode == KEY_S || keycode == KEY_C || \
        keycode == KEY_X || keycode == KEY_Q)
        event_decider(keycode, fract);
    else if (keycode == KEY_PLUS || keycode == KEY_MIN)
        event_shifts(keycode, fract);
    else if (keycode == KEY_J || keycode == KEY_M || \
        keycode == KEY_B)
        event_change_fract(keycode, fract);
    else if (keycode == KEY_SPATIE)
        ft_calc_zero(fract);
    event_key2(keycode, fract);
    ft_fract_base(fract);
    return (0);
}
