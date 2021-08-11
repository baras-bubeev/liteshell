# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/27 12:48:01 by mpowder           #+#    #+#              #
#    Updated: 2021/06/28 00:10:44 by mpowder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_strncmp.c ft_strnstr.c ft_tolower.c ft_toupper.c \
			ft_strrchr.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
			ft_memcmp.c ft_memchr.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memccpy.c ft_memmove.c ft_strdup.c ft_calloc.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS	= ${SRCS:.c=.o}

S_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

O_BONUS	= ${S_BONUS:.c=.o}

NAME	= libft.a

CC		= gcc

AR		= ar rc

RANL	= ranlib

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${INC}
			${AR} ${NAME} ${OBJS}
			${RANL} ${NAME}

all:		${NAME}

bonus:		${NAME} ${O_BONUS}
			${AR} ${NAME} ${O_BONUS}
			${RANL} ${NAME}

clean:
			${RM} ${OBJS} ${O_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
