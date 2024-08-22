# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 15:25:29 by vpelc             #+#    #+#              #
#    Updated: 2024/08/21 16:56:12 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF = ft_printf
PRINTF_NAME = ${PRINTF}/libftprintf.a 

CLIENT = client.c
CLIENT_NAME = client

SERVER = server.c
SERVER_NAME = server

CLIENT_BONUS = client_bonus.c
CLIENT_NAME_BONUS = client_bonus

SERVER_BONUS = server_bonus.c
SERVER_NAME_BONUS = server_bonus

CC = CC
CFLAGS = -Wall -Wextra -Werror

all : ${CLIENT_NAME} ${SERVER_NAME}

${PRINTF_NAME} : ${PRINTF_NAME}
		$(MAKE) -C ${PRINTF}

${CLIENT_NAME} : ${CLIENT_NAME} ${PRINTF_NAME}
		${CC} ${CFLAGS} -o $@ ${CLIENT} -L${PRINTF} -lftprintf

${SERVER_NAME} : ${SERVER_NAME} ${PRINTF_NAME} 
		${CC} ${CFLAGS} -o $@ ${SERVER} -L${PRINTF} -lftprintf
		
${CLIENT_NAME_BONUS} : ${CLIENT_NAME_BONUS} ${PRINTF_NAME}
		${CC} ${CFLAGS} -o $@ ${CLIENT_BONUS} -L${PRINTF} -lftprintf

${SERVER_NAME_BONUS} : ${SERVER_NAME_BONUS} ${PRINTF_NAME} 
		${CC} ${CFLAGS} -o $@ ${SERVER_BONUS} -L${PRINTF} -lftprintf

clean:
		$(MAKE) -C ${PRINTF} clean

fclean:		clean
	$(MAKE) -C ${PRINTF} fclean
		${RM} ${CLIENT_NAME} ${SERVER_NAME} ${CLIENT_NAME_BONUS} ${SERVER_NAME_BONUS}
		
re:		fclean all

bonus: ${CLIENT_NAME_BONUS} ${SERVER_NAME_BONUS} 

.PHONY = all clean fclean re