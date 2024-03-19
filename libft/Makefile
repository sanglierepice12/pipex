# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsuter <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 16:46:46 by gsuter            #+#    #+#              #
#    Updated: 2024/02/26 16:46:51 by gsuter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	ft_atoi.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_split.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strlen.c		\
			ft_strmapi.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_strtrim.c	\
			ft_substr.c		\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_printf.c		\
			ft_printf_utils.c\
			get_next_line.c

BNS		=	ft_lstadd_back.c	\
			ft_lstadd_front.c	\
			ft_lstclear.c		\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstlast.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_lstsize.c

OBJS	=	${SRCS:%.c=${OBJ_D}%.o}

B_OBJS	=	${BNS:%.c=${OBJ_D}%.o}

SRC_D	=	srcs/

OBJ_D	=	objs/

HEADER	=	incs/libft.h

NAME	=	libft.a

CC		=	cc

AR		=	ar -rc

FLAGS	=	-Wall -Wextra -Werror -Iincs

all		:
	@make --no-print-directory ${NAME}

${OBJS}	:	${OBJ_D}%.o	:	${SRC_D}%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile
	${AR} ${NAME} ${OBJS}

${OBJ_D}:
	@mkdir -p ${OBJ_D}

bonus	:
	@make ${NAME} SRCS="${SRCS} ${BNS}"

clean	:
	rm -rf ${OBJ_D}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re bonus
