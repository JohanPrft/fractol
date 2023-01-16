# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 11:30:12 by jprofit           #+#    #+#              #
#    Updated: 2023/01/16 11:30:14 by jprofit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	libmlx.a

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	src/

DIR_HEADERS		=	include/

# ---- Libs variables ---- #


UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
OS				=	linux
endif

ifeq ($(UNAME), Darwin)
OS				=	macos
endif

MLX_PATH		=	./mlx/${OS}/

MLX				=	${MLX_PATH}libmlx.a


# ---- Files ---- #

HEADERS_LIST	=

SRCS_LIST		=

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

# ---- Commands ---- #

MKDIR			=	mkdir -p

AR				=	ar rcs

# ********* RULES ******** #

all				:	${NAME}

opti			:
					${MAKE} re CFLAGS="-Wall -Wextra -Werror -fsanitize=address -O2"

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${HEADERS}
					make -C ${MLX_PATH}
					cp ${MLX} ${NAME}
					# ${AR} ${NAME} ${OBJS}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS} ${MLX}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -I ${MLX_PATH} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Rules ---- #

clean			:
					make -C ${MLX_PATH} clean
					${RM} ${OBJS}

fclean			:	clean
					${RM} ${NAME}
					${RM} ${MLX}

re				:	fclean all

norm			:
					norminette ${SRCS_LIST:%=${DIR_SRCS}%} ${HEADERS}

.PHONY:	all clean fclean re
