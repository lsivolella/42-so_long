# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 11:45:10 by lgoncalv          #+#    #+#              #
#    Updated: 2022/06/19 11:51:31 by lgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILER
CC				= gcc

# FLAGS
CFLAGS			= -Wall -Wextra -Werror
CFLAGS_DEBUG	= -Wall -Wextra -Werror -fsanitize=leak -static-libasan
LIBFTFLAGS		= -L $(LIBFT_PATH) -lft
MLXFLAGS		= -L $(MLX_PATH) -lmlx -lXext -lX11
INCLUDES		= -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -I $(MLX_PATH)

# PATHS
INCLUDES_PATH	= ./includes
SOURCES_PATH	= ./sources
OBJS_PATH		= ./objects
LIBS_PATH		= ./libs
LIBFT_PATH		= $(LIBS_PATH)/libft
MLX_PATH		= $(LIBS_PATH)/minilibx

# COMMANDS
RM				= /bin/rm -f
#/bin/rm is the absolute path to the rm program
# -f ignores nonexistent files, skipiing prompt

# NAMES
NAME			= so_long
NAME_BONUS		= so_long_bonus
MLX				= $(MLX_PATH)/libmlx.a
LIBFT			= $(LIBS_PATH)/libft.a

# SOURCES (common, mandatory, bonus)
SRCS_C			= main.c \
				get_next_line.c \
				sl_error_handler.c \
				sl_grid.c \
				sl_inputs.c \
				sl_map_read.c \
				sl_map_validate.c \
				sl_movement.c \
				sl_render.c \
				sl_setups.c \
				sl_vector_1.c \
				sl_vector_2.c \
				sl_vector_3.c

SRCS_M			= sl_utils_mandatory.c

SRCS_B			= sl_utils_bonus.c

SRCS_C			:= $(addprefix $(SOURCES_PATH)/,$(SRCS_C))
SRCS_M			:= $(addprefix $(SOURCES_PATH)/,$(SRCS_M))
SRCS_B			:= $(addprefix $(SOURCES_PATH)/,$(SRCS_B))

# OBJECTS
OBJS_C			= $(subst $(SOURCES_PATH), $(OBJS_PATH), $(SRCS_C:%.c=%.o))
OBJS_M			= $(subst $(SOURCES_PATH), $(OBJS_PATH), $(SRCS_M:%.c=%.o))
OBJS_B			= $(subst $(SOURCES_PATH), $(OBJS_PATH), $(SRCS_B:%.c=%.o))
# takes each string associated to SRCS and swaps the characters .c for .o

# PATTERN RULE
$(OBJS_PATH)/%.o : $(SOURCES_PATH)/%.c
		mkdir -p $(OBJS_PATH)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
# $(CC) $(CFLAGS) $(INCLUDES) -L lib -c $< -o $@
# shows make how to compile .c files into .o files

all:	clear_console $(NAME)

# rule on how to create the file associated to NAME variable (so_long)
$(NAME): $(LIBFT) $(MLX) $(OBJS_C) $(OBJS_M)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_C) $(OBJS_M) $(LIBFTFLAGS) $(MLXFLAGS) -o $@

bonus:	clear_console $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJS_C) $(OBJS_B)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_C) $(OBJS_B) $(LIBFTFLAGS) $(MLXFLAGS) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	$(MAKE) -C $(MLX_PATH)
# the flag -C is used for accessing directories before executing the command
# this command will run minilib's make. Thus, access MLX_PATH and then run make

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	$(RM) $(OBJS_C)
	$(RM) -r $(OBJS_M)
	$(RM) -r $(OBJS_B)

fclean:	clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re:	fclean all

clear_console:
	clear

run_clean:	all
	./$(NAME) ./maps/map_maze.ber
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) clean

run_clean_bonus:	bonus
	./$(NAME_BONUS) ./maps/map_maze.ber
	$(MAKE) clean

bonus:	clear_console $(BONUS)

rebonus: fclean bonus

clone_minilib:
	rm -fr "./libs/minilibx"
	git clone https://github.com/42Paris/minilibx-linux.git "./libs/minilibx"

valgrind:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck ./so_long ./maps/map_rectangle.ber

valgrind_bonus:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck ./so_long_bonus ./maps/map_rectangle.ber

valgrind_no_map:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck ./so_long
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck
# valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes
# valgrind --leak-check=full ./so_long ./maps/map_rectangle.ber

.PHONY:	all clean fclean re run_clean valgrind

# to review:
# $< (takes first argument of dependency?)

# clang main.c -lmlx -lXext -lXll
# clang main.c -L/libraries/minilibx -lmlx -L/libraries/minilibx -lXext -L/libraries/minilibx -lX11
# /usr/bin/ld: cannot find -lmlx
# /usr/bin/ld: cannot find -lx11

# gcc ./sources/main.c -lft -lmlx -lXext -lX11 -o test -I includes -I ./libs/minilibx -L ./libs -L ./libs/minilibx
# gcc ./sources/*.c -lft -lmlx -lXext -lX11 -o test -fsanitize=leak -g -I includes -I ./libs/minilibx -L ./libs -L ./libs/minilibx && ./test