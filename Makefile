# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 18:23:28 by hel-ouar          #+#    #+#              #
#    Updated: 2023/02/08 19:13:04 by hel-ouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS = src/main_pipex.c src/process_pipex.c src/utils_pipex.c

SRCB = bonus/here_doc_bonus.c bonus/main_pipex_bonus.c \
		bonus/process_pipex_bonus.c bonus/utils_pipex_bonus.c

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
