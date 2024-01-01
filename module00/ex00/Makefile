NAME		= 	ex00_megaphone
SRC			=	src/*.cpp
INCS		=	includes/
C++			=	clang++
CFLAGS		=	-std=c++98 -Wall -Werror -Wextra
RM			=	rm -f

all:	${NAME}


${NAME}: 
		${C++} ${CFLAGS} ${SRC} -I${INCS} -o ${NAME}

clean:
		${RM} ${INCS}/*.gch

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re

