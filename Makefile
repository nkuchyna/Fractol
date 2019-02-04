# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 19:00:52 by nkuchyna          #+#    #+#              #
#    Updated: 2018/05/20 15:58:41 by nkuchyna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fractol
CCLIB = libft/libft.a
CCMLX = -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
CCFLAGC = -Wall -Wextra -Werror
SRCDIR = src
OBJDIR = obj
INCDIR = includes libft

SRC  =  fractol.c\
		ft_define_fractol.c\
		ft_key_action.c\
		ft_mouse_action.c\
		ft_draw_fractol.c\
		ft_fractol_math1.c\
		ft_fractol_math2.c\
		additional.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS  = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS  =  $(addprefix -I, $(INCDIR))

all: $(NAME)

$(NAME): build $(OBJS)
		@make -C libft/
		@gcc $(CCLIB) $(CCMLX) -o $(NAME) $(OBJS)

build:
		@mkdir -p $(OBJDIR)

clean:
		rm -f $(OBJS)
		make clean -C libft

fclean: clean
		rm -f $(NAME)
		make fclean -C libft

re: fclean all

$(OBJDIR)/%.o : $(SRCDIR)/%.c
				gcc -c $(CCFLAGS) $(INCS) -o $@ $< 

.PHONY: clean fclean make re
