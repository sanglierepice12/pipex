SRCS	=	pipex.c		\
			process.c	\
			utils.c

OBJS	=	$(SRCS:%.c=${OBJ_D}%.o)

SRC_D	=	srcs/

OBJ_D	=	objs/

HEAD	=	includes/

NAME	=	pipex

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror -Iincludes -g

all		:
	@make --no-print-directory bonus -C libft/
	@make --no-print-directory ${NAME}

${OBJS}	:	${OBJ_D}%.o: ${SRC_D}%.c libft/incs/libft.h inc/pipex.h libft/libft.a
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile libft/incs/libft.h inc/pipex.h
	${CC} ${FLAGS} -o ${NAME} ${OBJS} -L./libft -lft

${OBJ_D}:
	@mkdir -p ${OBJ_D}

clean	:
	@echo "libft :"
	@make --no-print-directory clean -C ./libft
	@echo "pipex :"
	rm -rf ${OBJ_D}

fclean	:
	@echo "libft :"
	@make --no-print-directory fclean -C ./libft
	@echo "pipex :"
	rm -rf ${OBJ_D}
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
