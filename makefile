#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 16:04:24 by gboudrie          #+#    #+#              #
#    Updated: 2020/03/05 19:23:20 by gboudrie         ###   ########.fr        #
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
CC =		clang
CFLAGS =	-Wall -Wextra -Werror
LFLAGS =	-Iincludes/ -I

# binaries
EXE =       scop

# dir
SRC_DIR =       srcs
INC_DIR =       includes
OBJ_DIR =       obj

# sources
PROJ_SRC_LIST = main.c \
				window.c \
				events.c

# objects
PROJ_OBJ_LIST = $(PROJ_SRC_LIST:.c=.o)

#paths
PROJ_SRC =	$(addprefix $(SRC_DIR)/, $(PROJ_SRC_LIST))
PROJ_OBJ =	$(addprefix $(OBJ_DIR)/, $(PROJ_OBJ_LIST))

################################################################################

all :		    $(EXE)

$(EXE) :        $(PROJ_OBJ)
	            @$(CC) $(CFLAGS) $(LFLAGS) -lglfw -o $@ $(PROJ_OBJ)
	            @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$(EXE) "$(CLEAR)$(LIG)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	            @mkdir -p $(OBJ_DIR) 2> /dev/null || true
	            @$(CC) $(CFLAGS) $(LFLAGS) -c -o $@ $<
	            @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$< "$(CLEAR)$(LIG)"

meteo :
	            @curl http://wttr.in/Paris
	            @curl http://wttr.in/Moon

clean :
	            @echo "$(CLEAR)$(TRA)$(RED)  Cleaning Object $(CLEAR)$(TRA)"
	            @$(RM) $(PROJ_OBJ)
	            @rmdir $(OBJ_DIR) 2> /dev/null || true

fclean :	    clean
	            @echo "$(CLEAR)$(TRA)$(RED)  Removing Binary $(CLEAR)$(TRA)"
	            @$(RM) $(EXE)

re :		    fclean all

.PHONY :	    all, clean, fclean, re

.SILENT :