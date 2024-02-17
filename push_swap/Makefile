NAME = pushswap
SRCS_DIR = srcs
SRCS = ${addprefix ${SRCS_DIR}/, commands_p.c commands_r.c commands_rr.c commands_s.c \
								 main.c parsing.c pushswap.c utils.c}
OBJS = ${SRCS:.c=.o}
LIBFT_DIR = ./includes/libft
LIBFT = -L${LIBFT_DIR} -lft
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf


#.c.o:
#			cc ${CFLAGS} -c $< -o ${<:.c=.o} -I.

all:		${NAME}


${NAME}:	${OBJS}
			make -C ${LIBFT_DIR}
			mv ${LIBFT_DIR}/${LIBFT} .
			cc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}
#a finir !!!!
clean:
			${RM} ${OBJS}
			make clean -C ${LIBFT_DIR}

fclean:		clean
			${RM} ${NAME}
			make fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
