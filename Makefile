NAME		= libftprintf.a
LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
SRCS		= ft_printf.c
OBJS		= $(SRCS:%.c=%.o)

.c.o:
	$(CC) $(CFLAGS)  -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(RM) $(NAME)
	ar -rcs $(NAME) $(OBJS) $(LIBFT_A)
	
$(LIBFT_A):
	make --directory=$(LIBFT_DIR)

clean:
	make $@ --directory=$(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make $@ --directory=$(LIBFT_DIR)
	$(RM) $(NAME)

re:		fclean all

test: all
	$(CC) $(CFLAGS) -g main.c -L. -lftprintf && ./a.out

.PHONY:	all clean fclean re
