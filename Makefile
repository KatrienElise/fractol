
#/* ************************************************************************** */
#/*                                                                            */
#/*                                                        ::::::::            */
#/*   Makefile                                           :+:    :+:            */
#/*                                                     +:+                    */
#/*   By: kblum <kblum@student.codam.nl>               +#+                     */
#/*                                                   +#+                      */
#/*   Created: 2019/03/27 12:23:27 by rsteigen       #+#    #+#                */
#/*   Updated: 2019/05/01 17:52:00 by kblum         ########   odam.nl         */
#/*                                                                            */
#/* ************************************************************************** */

NAME = fractol
FLAGS = -Wall -Wextra -Werror
FUNCS =	heart.c event_key.c event_mouse.c julia.c mandelbrot.c test.c error.c \
text.c calc.c unknown.c color.c

all: $(NAME)

$(NAME):
	make -C minilibx_macos/ clean && make -C minilibx_macos/
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) -I includes/ -I minilibx_macos -c $(FUNCS)
	gcc $(FLAGS) -I includes/ -I minilibx_macos -c main.c
	gcc -o $(NAME) main.o $(FUNCS:.c=.o) -I includes -I minilibx_macos -L \
	libft/ -lft -L minilibx_macos -lmlx -framework OpenGL -framework APPkit

clean:
	/bin/rm -f $(FUNCS:.c=.o) main.o *~
	make -C libft/ fclean
	make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all