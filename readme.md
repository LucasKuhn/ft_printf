cc -Wall -Wextra -Werror -g main.c -L. -lftprintf

# Working - Compile main with lib ftprintf and lib ft from folder libft
cc -Wall -Wextra -Werror -g main.c -L. -lftprintf -L./libft -lft && ./a.out

