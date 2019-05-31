/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/30 16:24:28 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    ft_get_color(t_fractol *fract)
{
    //fract->color = *(t_color*) malloc(sizeof(t_color));
    //if (!fract->color)
   //     error_no_struct(1);

    if (fract->color.nb == 0)
        fract->color.base = BLUE;
    else if (fract->color.nb == 1)
        fract->color.base = RED;    
    else if (fract->color.nb == 2)
        fract->color.base = GREEN;    
    else if (fract->color.nb == 3)
        fract->color.base = PINK;    
    else if (fract->color.nb == 4)
        fract->color.base = YELLOW;  
    else if (fract->color.nb == 5)
        fract->color.base = DARK_GREEN;    
    else if (fract->color.nb == 6)
        fract->color.base = PURPLE;    
    else if (fract->color.nb == 7)
        fract->color.base = GOLD;    
    else if (fract->color.nb == 8)
        fract->color.base = BROWN;    
    else if (fract->color.nb == 9)
        fract->color.base = LIGHT_GREEN;
    else if (fract->color.nb == 10)
        fract->color.base = PINK2;
    else if (fract->color.nb == 11)
        fract->color.base = RED2;
}

void    color_stable(t_fractol *fract)
{
    if (fract->color.nb2 == 0)
        fract->color.stable = BLACK;
    else if (fract->color.nb2 == 1)
        fract->color.stable = RED;    
    else if (fract->color.nb2 == 2)
        fract->color.stable = LIME;    
    else if (fract->color.nb2 == 3)
        fract->color.stable = WHITE;    
    else if (fract->color.nb2 == 4)
        fract->color.stable = LIGHT_BLUE;  
    else if (fract->color.nb2 == 5)
        fract->color.stable = SPRINGGREEN;    
    else if (fract->color.nb2 == 6)
        fract->color.stable = ORANGE;    
    else if (fract->color.nb2 == 7)
        fract->color.stable = GOLD;    
    else if (fract->color.nb2 == 8)
        fract->color.stable = DARK_GREEN;    
    else if (fract->color.nb2 == 9)
        fract->color.stable = LIGHT_GREEN;
}