# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 22:20:12 by vrsargsy          #+#    #+#              #
#    Updated: 2022/03/18 19:08:19 by vrsargsy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   libft.a
ALL_SRCS = $(wildcard *.c)
SRCS_B	=   $(wildcard ft_lst*.c)
SRCS	=	$(filter-out $(SRCS_B), $(ALL_SRCS))
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): ${OBJS}
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME) $(OBJS_B)
	${LIBC} $(NAME) $(OBJS_B)
    
fclean: clean
	$(RM) $(NAME) $(bonus)

clean:
	$(RM) -f $(OBJS) $(OBJS_B)
    
re: fclean all

.PHONY: all bonus clean fclean re .c.o
