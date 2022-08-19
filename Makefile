# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 14:32:38 by cfontain          #+#    #+#              #
#    Updated: 2022/08/19 20:50:11 by tnoulens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

LIB_DIR		=	./libft

LIBFT		=	./libft/libft.a

MAIN		=	./srcs/main.c

CORE		=	./srcs/core/prompt.c\

BUILTIN		=	./srcs/built-in/ft_echo.c\
				./srcs/built-in/ft_env.c\
				./srcs/built-in/ft_exit.c\
				./srcs/built-in/ft_pwd.c\

UTILITIES	= 	./srcs/utilities/garbage_collector.c\
				./srcs/utilities/welcome_message.c\

SRCS		=	${MAIN} ${CORE} ${BUILTIN} ${UTILITIES}

OBJS		=	${SRCS:.c=.o} 

RM			=	rm -f

CC			=	cc -L/usr/lib/x86_64-linux-gnu

FLAGS		=	-Wall -Wextra -Werror -g 

all			: ${NAME}

%.o: %.c
		@${CC} ${FLAGS}  -c $< -o ${<:.c=.o} 

${LIBFT}	:
		@echo "\033[35m----Building libft----"
		@make -sC ${LIB_DIR}
		@echo "OK"

${NAME}		: ${OBJS}  ${LIBFT}
		@echo "\033[34m----Compiling----"
		@${CC} ${FLAGS} ${OBJS} -L -lm -lreadline -o ${NAME} ${LIBFT} 
		@echo "OK"

clean		:
		@echo "\033[31m----Cleaning libft----"
		@make clean -sC ${LIB_DIR}
		@echo "OK"
		@echo "\033[31m----Cleaning objects----"
		@${RM} ${OBJS}
		@echo "OK"

fclean		: clean
		@echo "\033[33m----Cleaning all----"
		@${RM} ${NAME}
		@${RM} ${LIBFT}
		@echo "OK"

re			: fclean all

minishell	: all
		valgrind --leak-check=full --show-leak-kinds=all ./minishell

.PHONY		: all clean fclean re
