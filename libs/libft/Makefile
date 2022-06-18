# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 10:31:36 by lgoncalv          #+#    #+#              #
#    Updated: 2022/05/28 15:42:08 by lgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a
OUT_FILES =		$(SRC:.c=.o)
B_OUT_FILES =	$(B_SRC:.c=.o)
CFLAGS =		-Wall -Werror -Wextra
HEADER =		libft.h
RANLIB =		ranlib
RM =			rm -f #-f ignores non existing files and arguments
PROGRAM =		./a.out
CC =			gcc

SRC =		ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strhaschr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

B_SRC =		ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

.c.o:
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

all:	$(FCLEAN) $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar -rsc $(NAME) $(OUT_FILES)
	@$(RANLIB) $(NAME)
	@echo "[INFO] Library [$(NAME)] created!"

bonus:
	@$(CC) $(CFLAGS) -c $(B_SRC)
	@ar -rsc $(NAME) $(B_OUT_FILES)
	@$(RANLIB) $(NAME)
	@echo "[INFO] Bonus created!"

clean:
	@$(RM) $(OUT_FILES) $(B_OUT_FILES)
	@echo "[INFO] Objects removed!"

fclean: clean
	@$(RM) $(NAME) $(PROGRAM)
	@echo "[INFO] Library [$(NAME)] removed!"

re: fclean all

rebonus: fclean bonus

so:
	$(CC) -fPIC $(CFLAGS) -c $(SRC) $(B_SRC)
	gcc -shared -o libft.so $(OUT_FILES) $(B_OUT_FILES)

.PHONY: all bonus clean fclean re