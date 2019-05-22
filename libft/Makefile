# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rsteigen <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/11 09:13:32 by rsteigen      #+#    #+#                  #
#    Updated: 2019/04/10 14:19:43 by rsteigen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
FLAGS = -Wall -Wextra -Werror
FUNCTIONS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
		   	ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strcpy.c ft_strncpy.c\
			ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c\
			ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c\
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c\
			ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
			ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
			ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c\
			ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
			ft_islower.c ft_isupper.c ft_lstpushback.c ft_print_list.c ft_lstlen.c\
			ft_calc.c ft_prime_check.c ft_sqrt.c get_next_line.c ft_abs.c

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c -I $(HEADER) $(FUNCTIONS)
	@ar rc $(NAME) $(FUNCTIONS:.c=.o)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(FUNCTIONS:.c=.o) *~

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
