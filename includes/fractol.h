/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblum <kblum@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/01 17:52:00 by kblum         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "color.h"
# include "keycodes.h"
# include <fcntl.h>


typedef struct      s_color
{
    int             nb;
    int             nb2;
    int             base;
    int             c;
    int             x;
    int             stable;
}                   t_color;

typedef struct      s_fractol
{
    void            *mlx;
    void            **win;
    void            *img;
    char            *data_addr;
    int             endian;
    int             bpp;
    int             sl;
    
    int             name;
    int             winw;
    int             winh;
    int             it;
    int             it_max;
    int             x;
    int             temp;
    int             y;
    int             infi;
    int             j_mouse;
    int             quit_mouse;
    int             shift;
    int             move_hor;
    int             move_vert;
    int             put_index;

    double          magni;
    double	    	zoom;
	double	    	x1;
	double	    	y1;
	double	    	c_r;
	double	    	c_i;
	double	    	z_r;
	double	    	z_i;
    double          tmp;
    double          change_jul;
    
    t_color         color;

}                   t_fractol;


/* ************************************************************************** */
/*          heart.c                                                           */
/* ************************************************************************** */
void    ft_win_mlx_img(t_fractol *fract);
int     ft_fractol_compare(char *str, int ac, t_fractol *fract);
void    ft_fract_base(t_fractol *fract);
void    ft_fract_set(t_fractol *fract);
int     entry(char **av, int ac);

/* ************************************************************************** */
/*          color.c                                                           */
/* ************************************************************************** */
void    ft_get_color(t_fractol *fract);
void    color_stable(t_fractol *fract);

/* ************************************************************************** */
/*          calc.c                                                           */
/* ************************************************************************** */
void    square(t_fractol *fract);
void    magnitude(t_fractol *fract);
void    add(t_fractol *fract);
void      ft_calc_zero(t_fractol *fract);
void     calc_winw_winh(int ac, char **av, t_fractol *fract);

/* ************************************************************************** */
/*          burningship.c                                                           */
/* ************************************************************************** */
void    ft_burningship_base(t_fractol *fract);
void    ft_calc_burningship(t_fractol *fract);
void    burningship(t_fractol *fract);

/* ************************************************************************** */
/*          event_key.c                                                       */
/* ************************************************************************** */
int     event_key2(int keycode, t_fractol *fract);
int     event_key(int keycode, t_fractol *fract);
int     event_shifts(int keycode, t_fractol *fract);
int     event_key_change(int keycode, t_fractol *fract);

/* ************************************************************************** */
/*          event_mouse.c                                                       */
/* ************************************************************************** */
int		mouse_julia(int x, int y, t_fractol *fract);
void    ft_out_zoom(int x, int y, t_fractol *fract);
void    ft_in_zoom(int x, int y, t_fractol *fract);
int     event_mouse(int mousecode, int x, int y, t_fractol *fract);
int     event_mouse_move(int x, int y, t_fractol *fract);


/* ************************************************************************** */
/*          julia.c                                                          */
/* ************************************************************************** */
int     mouse_julia(int x, int y, t_fractol *fract);
void    ft_julia_base(t_fractol *fract);
void    ft_calc_julia(t_fractol *fract);
void    julia(t_fractol *fract);

/* ************************************************************************** */
/*          mandelbrot.c                                                      */
/* ************************************************************************** */
void    ft_mandelbrot_base(t_fractol *fract);
void    ft_calc_mandel(t_fractol *fract);
void    mandelbrot(t_fractol *fract);

/* ************************************************************************** */
/*          test.c                                                            */
/* ************************************************************************** */
void	put_pixel_to_img(t_fractol *fract, int x, int y, int color);
void    test_print_values(t_fractol *fract);

/* ************************************************************************** */
/*          error.c                                                           */
/* ************************************************************************** */
void    exit_program(t_fractol *fract);
void    error_no_struct(int d);
void    error(t_fractol *fract, int d);

/* ************************************************************************** */
/*          text.c                                                            */
/* ************************************************************************** */
void    ft_put_text(t_fractol *fract);
void    ft_text_index(t_fractol *fract);

#endif