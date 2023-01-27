# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imac <imac@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:15:50 by jprofit           #+#    #+#              #
#    Updated: 2023/01/23 10:38:00 by imac             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	fractol

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	sources/

DIR_HEADERS		=	include/

# ---- Files ---- #

HEADERS_LIST	=	fractol.h

SRCS_LIST		=	main.c		init.c		draw.c		fractals.c			\
					hooks.c		utils.c		utils_hook.c

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CFLAGS			=	-Wall -Wextra -Werror -g -Ofast

LIBRARY			=	-L${MLX_PATH} -lmlx

# ---- OS Variables ---- #

UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
OS				=	linux
LIBRARY		+= -lXext -lX11 -lm -lz
endif

ifeq ($(UNAME), Darwin)
OS				=	macos
LIBRARY		+=	-framework OpenGL -framework AppKit
endif

MLX_PATH		=	./mlx/${OS}/

MLX				=	${MLX_PATH}libmlx.a

# ---- Commands ---- #

MKDIR			=	mkdir -p

RM				=	rm -rf

# ********* RULES ******** #

all				:	${NAME}

opti			:
					${MAKE} ${NAME} CFLAGS="-Wall -Wextra -Werror -fsanitize=address -O2"

# ---- Variables Rules ---- #

${NAME}			:	${MLX} ${DIR_OBJS} ${OBJS} ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} ${OBJS} ${LIBRARY} -o ${NAME}

# ---- Lib rules ---- #

${MLX}			:	FORCE
					make -C ${MLX_PATH}

FORCE			:

# ---- Compiled Rules ---- #

${OBJS}			:	${DIR_OBJS}%.o:	${DIR_SRCS}%.c ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Rules ---- #

run				:	all
					./${NAME}

leaks			:	all
					leaks --atExit -- ./${NAME}

clean			:
					${RM} ${OBJS}
					make -C ${MLX_PATH} clean

fclean			:	clean
					${RM} ${NAME} ${DIR_OBJS}

re				:	fclean all

debug			:
					@echo ${OBJS} ${HEADERS} ${MLX}

.PHONY:	all run clean fclean re debug
