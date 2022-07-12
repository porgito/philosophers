# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: porg <porg@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 16:11:21 by porg              #+#    #+#              #
#    Updated: 2022/06/08 19:25:27 by porg             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_atoi.c utils.c habits.c

OBJS	= ${SRCS:.c=.o}

GCC		= gcc -Wall -Werror -Wextra -lpthread

RM		= rm -f

NAME	= philo

all:		${NAME}

${NAME}:	${OBJS}
					${GCC} ${SRCS} -g -o ${NAME}

clean:
					${RM} ${OBJS}

fclean:		clean
					${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
