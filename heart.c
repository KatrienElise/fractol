/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heart.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/05 17:25:53 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void    ft_win_mlx_img(t_fractol *fract)
{
    fract->mlx = mlx_init();
    fract->win = mlx_new_window(fract->mlx, fract->winw, fract->winh, \
        "HAPPY FRACTOL");
	fract->img = mlx_new_image(fract->mlx, fract->winw, fract->winh);
	fract->data_addr = mlx_get_data_addr(fract->img,\
	&fract->bpp, &fract->sl, &fract->endian);
}

void    ft_fract_set(t_fractol *fract)
{
    if (fract->name == 1)
        julia(fract);
    else if (fract->name == 2)
        mandelbrot(fract);
    else if (fract->name == 3)
        burningship(fract);
    else
        sine(fract);
    mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
    if (fract->put_index == 1)
       ft_text_index(fract);
    ft_put_text(fract);
    //ft_reset_numbers(fract);
}
void    ft_fract_base(t_fractol *fract)
{
    if (fract->name == 1)
        ft_julia_base(fract);
    else if (fract->name == 2)
        ft_mandelbrot_base(fract);
    else if (fract->name == 3)
        ft_burningship_base(fract);
    else
        ft_sine_base(fract);
    ft_fract_set(fract); 
}

int    ft_fract_compare(char **str, int ac, t_fractol *fract)
{
    if (ft_strcmp(str[1], "julia") == 0)
        fract->name = 1;
    else if (ft_strcmp(str[1], "mandelbrot") == 0)
        fract->name = 2; 
    else if (ft_strcmp(str[1], "burningship") == 0)
        fract->name = 3;
    else if (ft_strcmp(str[1], "sine") == 0)
        fract->name = 4;
    else
    {
        ft_putstr("Usage: /fractol \"mandelbrot\", \"julia\"");
        ft_putstr(" \"burningship\", \"sine\"\n");
        return (0);
    }
    calc_winw_winh(ac, str, fract);
    return (1);
}

int     entry(char **av, int ac)
{
    t_fractol   *fract;

    fract = (t_fractol *) malloc(sizeof(t_fractol));
    if (!fract)
        error_no_struct(1);
    ft_bzero(fract->data_addr, (fract->winw * fract->winh) * 4);
    //ft_calc_zero(fract);
    if (ft_fract_compare(av, ac, fract) == 0)
        error(fract, 1);
    ft_win_mlx_img(fract);
    ft_fract_base(fract);
    mlx_hook(fract->win, 2, 1L << 0, event_key, fract);
	mlx_hook(fract->win, 4, 1L << 2, event_mouse, fract);
	mlx_hook(fract->win, 6, 1L << 13, event_mouse_move, fract);
    // mlx_clear_window(fract->mlx, fract->win); nodig?
    mlx_loop(fract->mlx);
    return (0); 
}