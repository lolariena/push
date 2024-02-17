NAME = libftprintf.a
SRCS_DIR = srcs
SRCS = ${addprefix ${SRCS_DIR}/, ft_printf.c ft_printf_utils.c ft_printf_dip.c}
OBJS = ${SRCS:.c=.o}
LIBFT_DIR = libft
LIBFT = libft.a
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf


.c.o:
			cc ${CFLAGS} -c $< -o ${<:.c=.o} -I.

all:		${NAME}


${NAME}:	${OBJS}
			make -C ${LIBFT_DIR}
			mv ${LIBFT_DIR}/${LIBFT} ./${NAME}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
			make clean -C ${LIBFT_DIR}

fclean:		clean
			${RM} ${NAME}
			make fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
