/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*  heart.c                                              :+:    :+:           */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 17:52:00 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void     ft_win_mlx_img(t_fractol *fract)
{
    fract->mlx = mlx_init();
    fract->win = mlx_new_window(fract->mlx, fract->winw, fract->winh, "FRACTOL");
	fract->img = mlx_new_image(fract->mlx, fract->winw, fract->winh);
	fract->data_addr = mlx_get_data_addr(fract->img,\
	&fract->bpp, &fract->sl, &fract->endian);
}

void    ft_fract_set(t_fractol *fract)
{
    if (fract->name == 1)
        ft_calc_julia(fract);
    if (fract->name == 2)
        mandelbrot(fract);
    else if (fract->name == 3)
        unknown(fract);
    mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
    ft_put_text(fract);
    //ft_reset(fract);
}
void    ft_base_func(t_fractol *fract)
{
    if (fract->name == 1)
        ft_julia_base(fract);        //sets struct values
    else if (fract->name == 2)
        ft_mandelbrot_base(fract);   //sets struct values
    else if (fract->name == 3)
        ft_unknown_base(fract);
    ft_fract_set(fract); //tekent de fractol to img?, is a port to specific fract function 
    //that will calculate wiht the set values and set pix to mem, and put img to wind.
    /* in de julie/mandel functies word data geset, en dan in 
    de laatste functie de fract_set word met deze data de fractol
    berekent?
    */

}

int    ft_fract_compare(char **str, int ac, t_fractol *fract)
{
    //test_print_values(fract);
    if (ft_strcmp(str[1], "julia") == 0)
        fract->name = 1;
    else if (ft_strcmp(str[1], "mandelbrot") == 0)
        fract->name = 2; 
    else if (ft_strcmp(str[1], "unknown") == 0)
        fract->name = 3;
    else
    {
        ft_putstr("Usage: /fractol \"mandelbrot\", \"julia\", \"unknown\"\n");
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
    if (ft_fract_compare(av, ac, fract) == 0)
        error(fract, 1);
    ft_calc_zero(fract);
    ft_win_mlx_img(fract);
    ft_base_func(fract); // port to functions of specific fracts, set first values.
    mlx_hook(fract->win, 2, 1L << 0, event_key, fract);
	mlx_hook(fract->win, 4, 1L << 2, event_mouse, fract);
    // mlx_clear_window(fract->mlx, fract->win); nodig?
    mlx_loop(fract->mlx);
    return (0); 
}