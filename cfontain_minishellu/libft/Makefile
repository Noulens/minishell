# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 12:36:32 by cfontain          #+#    #+#              #
#    Updated: 2022/08/05 10:53:06 by cfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c ft_printf.c ft_putnbrhex.c ft_putnbrstr.c ft_printf_error.c ft_putnbrstr_error.c ft_putnbrhex_error.c destroy_str.c

BONUSSRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

NAME		= libft.a

BONUSOBJS	= ${BONUSSRCS:.c=.o}

HEADER		= libft.h

OBJS		= ${SRCS:.c=.o}

CC		= gcc 

CFLAGS		= -Wall -Wextra -Werror

RM		= rm -f

all:		${NAME}

bonus		: ${HEADER}  ${OBJS} ${BONUSOBJS}
				ar rc ${NAME}  ${OBJS} ${BONUSOBJS}
				ranlib ${NAME}


${NAME}:	${HEADER} ${OBJS} 
			
			ar rc ${NAME} ${OBJS}

			ranlib ${NAME}
clean:
	${RM} ${OBJS} ${BONUSOBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
