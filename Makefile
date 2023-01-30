# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 18:23:28 by hel-ouar          #+#    #+#              #
#    Updated: 2023/01/30 16:05:00 by hel-ouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g #-fsanitize=address

SRCS = pipex.c branch.c

SRCB = main_bonus.c pipex_bonus.c

OBJB = $(SRCB:.c=.o)

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = pipex

HEAD = pipex.h

RM = rm -f

%.o: %.c Makefile ${HEAD}
		${CC} ${FLAGS} -ILibft -c $< -o $@

all: Libft $(NAME)

$(NAME): $(OBJS) Libft
	$(RM) $(OBJB)
	$(CC) $(OBJS) Libft/libft.a -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJB)
	${MAKE} clean -C Libft/

Libft :
	${MAKE} -C Libft
	
fclean: clean
	${MAKE} fclean -C Libft/
	$(RM) $(OBJS) $(OBJB)
	$(RM) $(NAME)
	
bonus : Libft $(OBJB)
	$(RM) $(OBJS)
	$(CC) ${FLAGS} $(OBJB) Libft/libft.a -o $(NAME)
	
re: fclean
	make all

.PHONY:	all clean fclean re bonus Libft
