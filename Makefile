# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 14:32:38 by cfontain          #+#    #+#              #
#    Updated: 2022/09/07 14:45:26 by cfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

LIB_DIR		=	./libft

LIBFT		=	./libft/libft.a

MAIN		=	./srcs/main.c

CORE		=	./srcs/core/prompt.c\
				./srcs/core/pipex.c\
				./srcs/core/execute.c\
				./srcs/core/m_parsing_quote.c\
				./srcs/core/m_split_init.c\
				./srcs/core/m_split_parse.c\
				./srcs/core/cut_quote.c\
				./srcs/core/parsing_token.c\
				./srcs/core/signals.c\
				./srcs/core/parsing_alias.c

BUILTIN		=	./srcs/built-in/ft_echo.c\
				./srcs/built-in/ft_env.c\
				./srcs/built-in/ft_exit.c\
				./srcs/built-in/ft_pwd.c

UTILITIES	= 	./srcs/utilities/garbage_collector.c\
				./srcs/utilities/welcome_message.c\
				./srcs/utilities/pipes_mgmt.c\
				./srcs/utilities/init.c

SRCS		=	${MAIN} ${CORE} ${BUILTIN} ${UTILITIES}

OBJS		=	${SRCS:.c=.o} 

RM			=	rm -f

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror -g -I includes/

SUPP		=	printf "{\n    leak readline\n    Memcheck:Leak\n    ...\n    fun:readline\n}\n{\n    leak add_history\n   Memcheck:Leak\n    ...\n    fun:add_history\n}" > ignore_leak.supp

all			: ${NAME}

%.o: %.c
		@${CC} ${FLAGS}  -c $< -o ${<:.c=.o}

${LIBFT}	:
		@echo "\033[35m----Building libft----"
		@make -sC ${LIB_DIR}
		@echo "OK\033[0m"

${NAME}		: ${OBJS}  ${LIBFT}
		@echo "\033[34m----Compiling----"
		@${CC} ${FLAGS} ${OBJS} -L/usr/include -lreadline -o ${NAME} ${LIBFT}
		@${SUPP}
		@echo "OK\033[0m"

clean		:
		@echo "\033[31m----Cleaning libft----"
		@make clean -sC ${LIB_DIR}
		@echo "OK"
		@echo "\033[31m----Cleaning objects----"
		@${RM} ${OBJS}
		@echo "OK\033[0m"

fclean		: clean
		@echo "\033[33m----Cleaning all----"
		@${RM} ${NAME}
		@${RM} ${LIBFT}
		@${RM} ignore_leak.supp
		@echo "OK\033[0m"

re			: fclean all

ms	: all
		valgrind --suppressions=ignore_leak.supp --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --verbose ./minishell

.PHONY		: all clean fclean re
