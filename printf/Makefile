# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 11:09:54 by vpelc             #+#    #+#              #
#    Updated: 2024/08/21 16:01:10 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

AR = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SOURCE = printf printf_hex printf_str_nbr \
		printf_utils printf_flag_bonus atoi

SOURCES = $(addsuffix .c, ${SOURCE})

OBJECTS = ${SOURCES:.c=.o}

all:	${NAME} 

bonus : ${NAME}

.c.o:
		${CC} ${CFLAGS} -I ./ -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
		${AR} ${NAME} ${OBJECTS}

clean:
		${RM} ${OBJECTS} 

fclean:		clean
		${RM} ${NAME} 

re:		fclean all
	
.PHONY: all clean fclean re bonus 