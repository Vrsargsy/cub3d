LIBFT = ./libft/libft.a

NAME = cube3D

SRCS = 	cube3D.c \
		$(wildcard game/*.c) \
		$(wildcard libft/*.c) \
		$(wildcard get_next_line/*.c)

CC = gcc

FLAGS = -Wall -Wextra -Werror -I./minilibx/mlx.h -lmlx -framework OpenGL -framework Appkit

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRCS) -o $(NAME)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
norm:
	norminette $(SRCS) $(wildcard *.h libft/*.h)

re : fclean all