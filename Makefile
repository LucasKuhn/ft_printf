NAME	= ft_printf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
SRCS	= ft_printf.c
LIBFT	= ./libft/libft.a
LIBFT	= ./libft/libft.a

.c.o:
	$(CC) $(CFLAGS)  -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C ./libft

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
