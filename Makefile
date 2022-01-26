# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 20:01:53 by ecorreia          #+#    #+#              #
#    Updated: 2022/01/20 18:47:54 by ecorreia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc

RM		=	rm -rf

FLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

SRC	=	src/so_long.c\
		src/get_next_line.c\
		src/get_next_line_utils.c\
		src/map_errors.c\
		src/save_map.c\
		src/utils.c\
		src/render_map.c\
		src/key_events.c\
		src/key_events_2.c

SRC_BONUS	=	bonus/so_long_bonus.c\
				bonus/get_next_line_bonus.c\
				bonus/get_next_line_utils_bonus.c\
				bonus/map_errors_bonus.c\
				bonus/save_map_bonus.c\
				bonus/utils_bonus.c\
				bonus/render_map_bonus.c\
				bonus/key_events_bonus.c\
				bonus/key_events_2_bonus.c\
				bonus/render_map_bonus_2.c

mac : $(SRC)
	$(MAKE) -C mlx
	@ $(CC) $(FLAGS) $(SRC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@ echo "mac compilation OK"

bonus : $(SRC_BONUS)
	$(MAKE) -C mlx
	@ $(CC) $(FLAGS) $(SRC_BONUS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@ echo "mac bonus compilation OK"

clean:	
	$(RM) .o
	@ echo "Object files deleted"
 
fclean: clean
	$(RM) $(NAME)
	$(RM) so_long.dSYM
	$(MAKE) clean -C mlx
	@ echo "Binary file deleted"

re: fclean
	make
	@ echo "Make re done"

.PHONY: mac bonus clean fclean re