# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkorey <jkorey@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 21:24:36 by jkorey            #+#    #+#              #
#    Updated: 2021/07/16 14:05:02 by jkorey           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	= -Wall -Wextra -Werror
INCL	= libft.h

SRCS	= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		   ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memcpy.c ft_memset.c \
		   ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		   ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memmove.c \
		   ft_memchr.c ft_memcmp.c ft_strdup.c ft_substr.c \
		   ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_C	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

BONUS_O	= $(BONUS_C:.c=.o)

OBJS	= $(SRCS:.c=.o)

NAME	= libft.a

.c.o:
			gcc $(FLAGS) -I$(INCL) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(INCL)
			ar -rcs $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

bonus:		$(NAME) $(BONUS_O)
			ar -rcs $(NAME) $(BONUS_O)
			ranlib $(NAME)

clean:
			/bin/rm -f $(OBJS) $(BONUS_O)

fclean:		clean
			/bin/rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus

