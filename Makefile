# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:15:50 by jprofit           #+#    #+#              #
#    Updated: 2023/01/16 10:15:57 by jprofit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	fractol

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	sources/

DIR_HEADERS		=	include/

# ---- Libs variables ---- #

SLX				=	slx/libslx.a

LIBFT			=	libft/libft.a

# ---- Files ---- #

HEADERS_LIST	=	fractol.h

SRCS_LIST		=	main.c

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

LIBRARY		=	-Llibft -Lslx -lft -lmlx

# ---- OS Variables ---- #

UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
LIBRARY		+= -lXext -lX11 -lm -lz
endif

ifeq ($(UNAME), Darwin)
LIBRARY		+=	-framework OpenGL -framework AppKit
endif

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all				:	${NAME}

opti			:
					${MAKE} ${NAME} CFLAGS="-Wall -Wextra -Werror -fsanitize=address -O2"

# ---- Variables Rules ---- #

${NAME}			:	${OBJS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} ${OBJS} ${LIBRARY} -o ${NAME}

# ---- Lib rules ---- #

${SLX}			:
					make -C slx

${LIBFT}		:
					make -C libft

FORCE			:

# ---- Compiled Rules ---- #

${OBJS}			:	${DIR_OBJS}%.o:	${DIR_SRCS}%.c Makefile ${HEADERS} ${LIBFT} ${SLX}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}
					make -C slx clean
					make -C libft clean

fclean			:	clean
					${RM} ${NAME}
					make -C slx fclean
					make -C libft fclean

re				:	fclean all

debug			:
					@echo ${OBJS} ${HEADERS} ${LIBFT} ${SLX}

.PHONY:	all clean fclean re debug