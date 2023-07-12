# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 00:25:46 by yorlians          #+#    #+#              #
#    Updated: 2023/03/24 00:35:45 by yorlians         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME		= pipex

SRCS		= pipex.c utils.c
OBJS		= $(SRCS:.c=.o)

LIBFT		= ./libft/
LIBFT_LIB	= ./libft/libft.a

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			make bonus -C $(LIBFT) && make clean -C $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
			echo compiling pipex

clean:
			$(RM) $(OBJS)
			echo cleaning object files

fclean:		clean
			make fclean -C $(LIBFT)
			$(RM) $(NAME)
			echo cleaning program files

re:			fclean all

.PHONY:		all clean fclean re
