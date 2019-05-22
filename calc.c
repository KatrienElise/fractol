/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 17:52:00 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    square(t_fractol *fract)
{
     fract->temp = (fract->a * fract->a) - (fract->b * fract->b);
     fract->b = 2.0 * fract->a * fract->b;
     fract->a = fract->temp;
}

void  magnitude(t_fractol *fract)
{
    double  a;
    double  b;
    
    a = fract->a * fract->a;
    b = fract->b * fract->b;
    fract->magni = ft_sqrt(a * b);
}

void    add(t_fractol *fract)
{
     fract->a = fract->a + fract->ca;
     fract->b = fract->b + fract->cb;
}