/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/06 13:09:29 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_mandelbrot_base(t_fractol *fract)
{
	if (!fract->it_max)
    	fract->it_max = 40;
	if (fract->zoom == 0)
		fract->zoom = 1.3;
	if (!fract->x1)
		fract->x1 = -0.7;
	if (!fract->y1)
		fract->y1 = 0; 
  	fract->y = 0;
	fract->infi = 6;
	ft_get_color(fract);
	color_stable(fract);	
}

static void  magnitude(t_fractol *fract)
{
    fract->magni = fract->z_r * fract->z_r + 
     fract->z_i * fract->z_i;
}

static void    ft_calc_mandel(t_fractol *fract)
{
  	fract->c_r = (fract->x - fract->winw / 2) / 
		( 0.25 * fract->zoom * fract->winw) + fract->x1;
	fract->c_i = (fract->y - fract->winh / 2) / 
		( 0.25 * fract->zoom * fract->winh) + fract->y1;
	fract->z_r = fract->c_r;
	fract->z_i = fract->c_i;
	fract->it = 0;
	magnitude(fract);
	while (fabs(fract->z_r + fract->z_i) < fract->infi && fract->it < fract->it_max)
	{
      fract->tmp = fract->z_r;
      fract->z_r = fract->z_r * fract->z_r - \
		     fract->z_i * fract->z_i + fract->c_r;
	    fract->z_i = 2 * fract->z_i * fract->tmp + fract->c_i;
		fract->it++;
	}
	if (fract->it == fract->it_max)
		put_pixel_to_img(fract, fract->x, fract->y, fract->color.stable);
	else
		put_pixel_to_img(fract, fract->x, fract->y, \
			(fract->color.base * (fract->it)));
}

static void    *mandelbrot(void *fract)
{
	t_fractol	*fract2;

	fract2 = (t_fractol*)fract;
	while (fract2->y < fract2->y_max)
	{
		fract2->x = 0;
		while (fract2->x < fract2->winw)
		{
			ft_calc_mandel(fract2);
			fract2->x++;			
		}
		fract2->y++;
    }
	return (fract);
}

void	speedy_mandel(t_fractol *fract)
{
	int			amount;
	int 		i;
	pthread_t	multi[THREAD_NUM];
	t_fractol	copy[THREAD_NUM];

	amount = fract->winh / THREAD_NUM;
	i = 0;
	while (i < THREAD_NUM)
	{
		ft_memcpy((void*)&copy[i], (void*)fract, sizeof(t_fractol));
		copy[i].y = amount * i;
		copy[i].y_max = amount * (i + 1);
		pthread_create(&multi[i], NULL, mandelbrot, &copy[i]);
		i++;
	}
	while(i >= 0)
	{
		pthread_join(multi[i], NULL);
		i--;
	}
}