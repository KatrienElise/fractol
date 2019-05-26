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

typedef struct      s_fractol
{
    void            *mlx;
    void            **win;
    void            *img;
    char            *data_addr;
    int             name;
    int             endian;
    int             bpp;
    int             sl;
    int             it;
    int             it_max;
    int             no_event;
    int             color;
    int             color_nb;
    int             x;
    int             y;
    int             infi;
    int             winw;
    int             winh;

    double          a;
    double          b;
    double          temp;
    double          magni;
    double          y_max;
    double          z;
    double          c;
    double          ca;
    double          cb;

    double	    	zoom;
	double	    	x1;
	double	    	y1;
    double          x_m;
    double          y_m;
    double          stop;
    double          nb;
	double	    	c_r;
	double	    	c_i;
	double	    	z_r;
	double	    	z_i;
	double	    	tmp;

}                   t_fractol;

/* ************************************************************************** */
/*          heart.c                                                           */
/* ************************************************************************** */
void    ft_win_mlx_img(t_fractol *fract);
int     ft_fractol_compare(char *str, int ac, t_fractol *fract);
void    ft_base_func(t_fractol *fract);
void    ft_fract_set(t_fractol *fract);
int     entry(char **av, int ac);

/* ************************************************************************** */
/*          color.c                                                           */
/* ************************************************************************** */
void    ft_get_color(t_fractol *fract);

/* ************************************************************************** */
/*          calc.c                                                           */
/* ************************************************************************** */
void    square(t_fractol *fract);
void    magnitude(t_fractol *fract);
void    add(t_fractol *fract);
void      ft_calc_zero(t_fractol *fract);
void     calc_winw_winh(int ac, char **av, t_fractol *fract);

/* ************************************************************************** */
/*          calc.c                                                           */
/* ************************************************************************** */
void    ft_unknown_base(t_fractol *fract);
void    ft_calc_unknown(t_fractol *fract);
void    unknown(t_fractol *fract);

/* ************************************************************************** */
/*          events.c                                                          */
/* ************************************************************************** */
int     event_key(int keycode, t_fractol *fract);
int     event_key_change(int keycode, t_fractol *fract);
void    ft_in_zoom(int x, int y, t_fractol *fract);
void    ft_out_zoom(int x, int y, t_fractol *fract);
int     event_mouse(int mousecode, int x, int y, t_fractol *fract);

/* ************************************************************************** */
/*          julia.c                                                          */
/* ************************************************************************** */
void    ft_julia_base(t_fractol *fract);
void    ft_calc_julia(t_fractol *fract);

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

#endif