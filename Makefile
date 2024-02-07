# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 16:48:25 by geargenc          #+#    #+#              #
#    Updated: 2018/02/20 13:23:14 by geargenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT		:

NAME		=	fdf

FILES		=	ft_bar.c\
				ft_calc.c\
				ft_clrpick_event.c\
				ft_color_event.c\
				ft_colorpicker.c\
				ft_config.c\
				ft_config_mlx.c\
				ft_cursor.c\
				ft_error.c\
				ft_img.c\
				ft_img_lineput.c\
				ft_imgtools.c\
				ft_mouse_event.c\
				ft_other_event.c\
				ft_parsefdf.c\
				ft_rot.c\
				ft_rotzoomdown_event.c\
				ft_rotzoomup_event.c\
				ft_shift_event.c\
				ft_sqr.c\
				main.c

SRC			=	$(addprefix src/, $(FILES))

OBJ			=	$(FILES:.c=.o)

INC			=	includes/ libft/includes/ minilibx/

HEADERS		=	includes/fdf.h\
				includes/ft_clrpick.h\
				includes/ft_colorpicker.h\
				includes/mlx_keycode.h\
				minilibx/mlx.h\
				libft/includes/libft.h\
				libft/includes/get_next_line.h

LIB			=	libft/ minilibx/

COMP		=	clang -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	lib $(OBJ)
	@$(COMP) $(addprefix -I , $(INC)) -o $(NAME) $(OBJ)\
		libft/libft.a minilibx/libmlx.a -lm -lXext -lX11
	@echo "\033[1;32m$(NAME) created !\033[0m"

lib			:
	@echo "\033[1;36mMaking libft...\033[0m"
	@make -C libft/
	@echo "\033[1;36mMaking minilibx...\033[0m"
	@make -C minilibx/

$(OBJ)		:	%.o: src/%.c $(HEADERS)
	@echo "\033[1;32m$< -> $@\033[0m"
	@$(COMP) $(addprefix -I , $(INC)) -c $< -o $@

clean		:
	@rm -rf $(OBJ)
	@echo "\033[1;32m$(OBJ) removed !\033[0m"

fclean		:	clean
	@rm -rf $(NAME)
	@echo "\033[1;32m$(NAME) removed !\033[0m"
	@echo "\033[1;36mCleaning libft...\033[0m"
	@make -C libft/ fclean
	@echo "\033[1;36mCleaning minilibx...\033[0m"
	@make -C minilibx/ clean

re			:	fclean all

easy		:	all clean

.PHONY		:	clean fclean
