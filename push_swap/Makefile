NAME = push_swap
SRCS_DIR = srcs
SRCS = ${addprefix ${SRCS_DIR}/, commands_p.c commands_r.c commands_rr.c commands_s.c \
								 main.c parsing.c push_swap.c utils.c parsing_utils.c}
								 #\push_swap_utils.c}
OBJS = ${SRCS:.c=.o}
LIBFT_DIR = ./includes/libft
LIBFT = -L${LIBFT_DIR} -lft
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf


.c.o:
			@cc ${CFLAGS} -c $< -o ${<:.c=.o} -I.

all:		${NAME}


${NAME}:	${OBJS}
			@make -C ${LIBFT_DIR}
			#mv ${LIBFT_DIR}/${LIBFT} .
			@cc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}
			@echo "\e[38;5;82mCompilation OK\033[0m"	

clean:
			@${RM} ${OBJS}
			@make clean -C ${LIBFT_DIR}
			@echo "\e[38;5;82mclean OK\033[0m"	

fclean:		clean
			@${RM} ${NAME}
			@make fclean -C ${LIBFT_DIR}
			@echo "\e[38;5;82mfclean OK\033[0m"	

re: fclean all

.PHONY: all clean fclean re
