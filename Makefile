# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 11:45:10 by lgoncalv          #+#    #+#              #
#    Updated: 2022/05/21 11:31:50 by lgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILER
CC				= gcc

# FLAGS
CFLAGS			= -Wall -Wextra -Werror
FTFLAGS			= -L $(LIBS_PATH) -lft
#MLXFLAGS		= -Lmlx_linux -Ilmlx -lXext -lX11 # TODO: review this
MLXFLAGS		= -L $(MLX_PATH) -lmlx -lXext -lX11
INCLUDES		= -I $(INCLUDES_PATH) -I $(MLX_PATH)
#INCLUDES		= -I $(INCLUDES_PATH)

# PATHS
INCLUDES_PATH	= ./includes
SOURCES_PATH	= ./sources
OBJS_PATH		= ./objects
LIBS_PATH		= ./libs
MLX_PATH		= $(LIBS_PATH)/minilibx

# COMMANDS
RM				= /bin/rm -f
#/bin/rm is the absolute path to the rm program
# -f ignores nonexistent files, skipiing prompt

# NAMES
NAME			= so_long
MLX				= $(MLX_PATH)/libmlx.a
LIBFT			= $(LIBS_PATH)/libft.a
SO_LONG			= so_long.h

# SOURCES
SRCS			= main.c \
				sl_error_handler.c \
				vector2.c \

SRCS			:= $(addprefix $(SOURCES_PATH)/,$(SRCS))
SO_LONG			:= $(addprefix $(INCLUDES_PATH)/,$(SO_LONG))

# OBJECTS
OBJS			= $(subst $(SOURCES_PATH), $(OBJS_PATH), $(SRCS:%.c=%.o))
# takes each string associated to SRCS and swaps the characters .c for .o

# PATTERN RULE
$(OBJS_PATH)/%.o : $(SOURCES_PATH)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
# shows make how to compile .c files into .o files
# included link to include and mlx path directories

all:	clear_console $(NAME)

# rule on how to create the file associated to NAME variable (so_long)
$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $@
# $(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) $(MLX) $(MLXFLAGS) -o $@
# TODO: review this command -> how is this working, exactly?

$(MLX):
	$(MAKE) -C $(MLX_PATH)
# the flag -C is used for accessing directories before executing the command
# this command will run minilib's make. Thus, access MLX_PATH and then run make

clean:
	$(MAKE) -C $(MLX_PATH) clean
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

clear_console:
	clear

run_clean:	re
	./so_long
	$(RM) $(OBJS)
	
bonus:	all

rebonus: fclean bonus

manminilib:
	man $(MINILIBX_PATH)/man/$(arg)

.PHONY:	all clean fclean re run_clean

# to review:
# $< (takes first argument of dependency?)

# clang main.c -lmlx -lXext -lXll
# clang main.c -L/libraries/minilibx -lmlx -L/libraries/minilibx -lXext -L/libraries/minilibx -lX11
# /usr/bin/ld: cannot find -lmlx
# /usr/bin/ld: cannot find -lx11