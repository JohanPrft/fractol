# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imac <imac@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:15:50 by jprofit           #+#    #+#              #
#    Updated: 2023/02/03 12:59:28 by jprofit          ###   ########.fr        #
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

CFLAGS			=	-Wall -Wextra -Werror -Ofast

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

# ---- Variables Rules ---- #

${NAME}			:	${MLX} ${DIR_OBJS} ${OBJS} ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} ${OBJS} ${LIBRARY} -o ${NAME}

# ---- Lib rules ---- #

${MLX}			:	FORCE
					make -C ${MLX_PATH}

FORCE			:

# ---- Compiled Rules ---- #

${OBJS}			:	${DIR_OBJS}%.o:	${DIR_SRCS}%.c ${HEADERS} Makefile
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Rules ---- #

run				:	all
					./${NAME}

clean			:
					${RM} ${OBJS}
					make -C ${MLX_PATH} clean

fclean			:	clean
					${RM} ${NAME} ${DIR_OBJS}

re				:	fclean all

debug			:
					@echo ${OBJS} ${HEADERS} ${MLX}

.PHONY:	all run clean fclean re debug
