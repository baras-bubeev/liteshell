SRCS	=	main.c \
			srcs/ft_add_line_in_arr.c srcs/ft_builtin.c srcs/ft_calloc.c \
			srcs/ft_cd.c srcs/ft_cd_direction.c srcs/ft_child_process.c \
			srcs/ft_close_fd.c srcs/ft_concatenate_str_in_arr.c \
			srcs/ft_count_char.c srcs/ft_count_cmd_argv.c srcs/ft_echo.c \
			srcs/ft_env.c srcs/ft_error1.c srcs/ft_error2.c srcs/ft_exit.c \
			srcs/ft_export.c srcs/ft_find_string.c srcs/ft_fork.c srcs/ft_free.c \
			srcs/ft_make_arr.c srcs/ft_path.c srcs/ft_pwd.c srcs/ft_replace_str_in_arr.c \
			srcs/ft_single_buildin.c srcs/ft_sort_and_print_arr.c srcs/ft_strcmp.c \
			srcs/ft_strdup_bonus.c srcs/ft_swap_strings.c srcs/ft_unset.c srcs/loop.c \
			srcs/minishell.c srcs/redirect.c srcs/shlvl.c srcs/str_check.c srcs/utils.c

OBJS	= $(SRCS:.c=.o)

NAME	= minishell

CC		= gcc

RM		= rm -f

CFLAGS	= -g -Wall -Wextra -Werror

RL_LIB	= -lreadline -L/Users/$(USER)/.brew/opt/readline/lib

RL_INC	= -I/Users/$(USER)/.brew/opt/readline/include

.c.o:
			$(CC) $(CFLAGS) $(RL_INC) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@make -C libft/
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a $(RL_LIB)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			@make clean -C libft/

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re