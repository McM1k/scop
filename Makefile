#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 13:37:15 by gboudrie          #+#    #+#              #
#    Updated: 2016/01/21 17:56:02 by gboudrie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =		libft.a

OUT =		exec.out

MAIN =		main.c

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

SOURCES =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c ft_isupper.c ft_islower.c \
			ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
			ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
			ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
			ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_isspace.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
			ft_lstiter.c ft_lstmap.c ft_pow.c ft_sqrt.c ft_lstlast.c \
			ft_lstaddq.c

OBJS =		$(SOURCES:.c=.o)

all :		$(NAME)

$(NAME) :	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

exec :		$(NAME)
			$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $(OUT)

norm :
			norminette $(SOURCES)

clean :
			-rm $(OBJS)

fclean :	clean
			-rm -f $(OUT) $(NAME)

re :		fclean all
