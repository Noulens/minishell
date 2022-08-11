# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 14:32:38 by cfontain          #+#    #+#              #
#    Updated: 2022/08/05 15:59:46 by cfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

LIB_DIR		= ./libft

LIBFT		= ./libft/libft.a

SRCS		= main.c check_path.c str_triple_join.c init.c destroy_all.c parse_command.c username.c fork.c ft_builtin.c

OBJS		= ${SRCS:.c=.o} 

RM		= rm -f

CC		= gcc -L/usr/lib/x86_64-linux-gnu 

FLAGS		=   -Wall -Wextra -Werror -g 

all		: ${NAME}

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

re		: fclean all

.PHONY		: all clean fclean re
