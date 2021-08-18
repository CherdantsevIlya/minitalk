SRC1	=	client.c
SRC2	=	server.c
SRC_B1	=	client_bonus.c
SRC_B2	=	server_bonus.c

HEADER	=	minitalk.h

OBJ1	=	${SRC1:.c=.o}
OBJ2	=	${SRC2:.c=.o}
OBJ_B1	=	${SRC_B1:.c=.o}
OBJ_B2	=	${SRC_B2:.c=.o}

NAME1	=	client
NAME2	=	server
NAME_B1	=	client_bonus
NAME_B2	=	server_bonus

CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc
RM		=	rm -f

all:		${NAME1} ${NAME2}
bonus:		${NAME_B1} ${NAME_B2}

${NAME1}:	${OBJ1}
			@$(CC) $(CFLAGS) ${OBJ1} -o ${NAME1}
			@printf "\x1b[32mclient ready 👌\x1b[0m\n"

${NAME2}:	${OBJ2}
			@$(CC) $(CFLAGS) ${OBJ2}  -o ${NAME2}
			@printf "\x1b[32mserver ready ✅\x1b[0m\n"

${NAME_B1}:	${OBJ_B1}
			@$(CC) $(CFLAGS) ${OBJ_B1} -o ${NAME_B1}
			@printf "\x1b[32m[BONUS] client ready 👌\x1b[0m\n"

${NAME_B2}:	${OBJ_B2}
			@$(CC) $(CFLAGS) ${OBJ_B2} -o ${NAME_B2}
			@printf "\x1b[32m[BONUS] server ready ✅\x1b[0m\n"

%.o: 		%.c ${HEADER}
			@$(CC) $(CFLAGS) -c $<

clean:
			@${RM} ${OBJ1} ${OBJ2} ${OBJ_B1} ${OBJ_B2}
			@printf "\x1b[31mclean done 🗑  (.o files)\x1b[0m\n"

fclean:		clean
			@${RM} ${NAME1} ${NAME2} ${NAME_B1} ${NAME_B2}
			@printf "\x1b[31mfclean done 🚽  (binaries)\x1b[0m\n"

re:		fclean all bonus

.PHONY:		all clean fclean re