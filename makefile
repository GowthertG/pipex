
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 13:48:39 by hhaddouc          #+#    #+#              #
#    Updated: 2021/11/20 16:10:24 by hhaddouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	mandatory/mandatory.a

BONUS	=	pipex_bonus/bonus.a

AR = ar rc

SRC     =	mandatory/pipex.c mandatory/utils.c mandatory/utils2.c\
		mandatory/libft_fun/ft_putchar_fd.c mandatory/libft_fun/ft_putstr_fd.c\
		mandatory/libft_fun/ft_split.c mandatory/libft_fun/ft_strchr.c mandatory/libft_fun/ft_strdup.c\
		mandatory/libft_fun/ft_strjoin.c mandatory/libft_fun/ft_strlen.c \
		mandatory/libft_fun/ft_strncmp.c mandatory/libft_fun/ft_substr.c\

OBG	=	$(SRC:.c=.o)

B_SRC	=	pipex_bonus/pipex_bonus.c pipex_bonus/utils_bonus.c pipex_bonus/pipex_utils_bonus2.c\
		pipex_bonus/child.c pipex_bonus/libft_fun_bonus/ft_putstr_fd.c\
		pipex_bonus/libft_fun_bonus/ft_split.c pipex_bonus/libft_fun_bonus/ft_strchr.c\
		pipex_bonus/libft_fun_bonus/ft_strdup.c pipex_bonus/libft_fun_bonus/ft_strjoin.c\
		pipex_bonus/libft_fun_bonus/ft_strlen.c pipex_bonus/libft_fun_bonus/ft_strncmp.c\
		pipex_bonus/libft_fun_bonus/ft_substr.c pipex_bonus/libft_fun_bonus/ft_putchar_fd.c\

B_OBG	=	$(B_SRC:.c=.o)

all:	$(NAME)

$(NAME)	:	$(OBG)
	$(AR) $(NAME) $(OBG)
	$(CC) $(CFLAGS) $(OBG) $(NAME)  -o pipex

bonus:	$(BONUS)

$(BONUS): $(B_OBG)
	$(AR) $(BONUS) $(B_OBG)
	$(CC) $(CFLAGS) $(B_OBG) -o pipex

clean:

	rm -rf $(OBG)
	rm -rf $(B_OBG)

fclean: clean
	rm -f pipex
	rm -rf $(NAME)
	rm -rf $(BONUS)

re:	fclean all

.PHONY: all clean fclean re
