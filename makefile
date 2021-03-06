#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 16:04:24 by gboudrie          #+#    #+#              #
#    Updated: 2020/09/24 16:34:14 by gboudrie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ansi chars
LOG = 	\033[2K
BLUE = 	\033[1;34m
YELLOW =\033[1;33m
GREEN =	\033[1;32m
RED =	\033[1;31m
CLEAR =	\033[0m
BOLD =	\033[1m
UNDERL =\033[4m
SHI =	\xF0\x9F\x9B\xA1
TRA =	\xF0\x9F\x97\x91
LIG =	\xE2\x9A\xA1
BR_V =	\xe2\x95\x91
BR_H =	\xe2\x95\x90
CR_UR =	\xe2\x95\x97
CR_UL =	\xe2\x95\x94
CR_DR =	\xe2\x95\x9d
CR_DL =	\xe2\x95\x9a

# comp
CC =			clang
CFLAGS =		-Wall -Wextra -Werror
IFLAGS =		-I$(HOME)/.brew/include -Iinc -Ilib
LFLAGS =		-L$(HOME)/.brew/lib -Llib/libft -lft -lm -ldl -lglfw
#ifeq($(UNAME),Darwin)
#	LFLAGS += -lglfw.3
#endif
#ifeq($(UNAME),Linux)
#	LFLAGS += -lglfw3

# binaries
EXE =			scop

# dir
SRC_DIR =       src
INC_DIR =       inc
OBJ_DIR =       obj

# sources
PROJ_SRC_LIST = main.c \
				window.c \
				events.c \
				glad.c \
				shader.c \
				image_reader.c \
				obj_reader.c \
				matrix_transformations.c \
				matrix_operations.c \
				matrix_utils.c \
				matrix_mvp.c \
				matrix_rev.c \
				obj_init.c \
				utils.c \
				textures.c \
				init.c \
				loop.c

# objects
PROJ_OBJ_LIST = $(PROJ_SRC_LIST:.c=.o)

#paths
PROJ_SRC =		$(addprefix $(SRC_DIR)/, $(PROJ_SRC_LIST))
PROJ_OBJ =		$(addprefix $(OBJ_DIR)/, $(PROJ_OBJ_LIST))

UNAME := $(shell uname)

################################################################################

all :		 	dep $(EXE)

$(EXE) :        $(PROJ_OBJ)
	            @$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(PROJ_OBJ) $(LFLAGS)
	            @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$(EXE) "$(CLEAR)$(LIG)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	            @mkdir -p $(OBJ_DIR) 2> /dev/null || true
	            @$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<
	            @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$< "$(CLEAR)$(LIG)"

norm :
				norminette $(PROJ_SRC)

meteo :
	            @curl http://wttr.in/Paris
	            @curl http://wttr.in/Moon

clean :
	            @echo "$(CLEAR)$(TRA)$(RED)  Cleaning Object $(CLEAR)$(TRA)"
	            @$(RM) $(PROJ_OBJ)
	            @rmdir $(OBJ_DIR) 2> /dev/null || true
#				rm *~ src/*~ inc/*~

fclean :	    depclean clean
	            @echo "$(CLEAR)$(TRA)$(RED)  Removing Binary $(CLEAR)$(TRA)"
	            @$(RM) $(EXE)

re :		    fclean all

.PHONY :	    all, clean, fclean, re

.SILENT :

dep :
			if [ $(UNAME) = "Linux" ]; then sudo apt-get install libglfw3; sudo apt-get install libglfw3-dev; fi
			if [ $(UNAME) = "Darwin" ]; then brew install glfw3;	fi
			sh glad.sh
			make -C lib/libft

depclean:
			@rm -rf inc/glad inc/glad.h inc/khrplatform.h inc/KHR src/glad.c
			make -C lib/libft fclean 
