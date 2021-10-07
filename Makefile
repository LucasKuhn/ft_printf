NAME		= libftprintf.a
LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
SRCS		= ft_printf.c ft_hexhandlers.c ft_numberhandlers.c ft_stringhandlers.c
OBJS		= $(SRCS:%.c=%.o)

.c.o:
	$(CC) $(CFLAGS)  -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	ar -rcs $(NAME) $(OBJS)
	
$(LIBFT_A):
	make --directory=$(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(NAME)

clean:
	make $@ --directory=$(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make $@ --directory=$(LIBFT_DIR)
	$(RM) $(NAME)

re:		fclean all

test: all
	$(CC) $(CFLAGS) main.c -L. -lftprintf -L./libft -lft && ./a.out

.PHONY:	all clean fclean re
