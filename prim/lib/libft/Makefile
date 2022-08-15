
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 22:04:39 by mbourgeo          #+#    #+#              #
#    Updated: 2022/08/15 15:53:11 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

SRCS	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
				ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c ft_printf.c ft_printf_functions_1.c ft_printf_functions_2.c
SRCDIR	=	src
LB_PATH	=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJDIR	=	obj
OBJS	=	$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(LB_PATH:.c=.o))
HDDIR	=	inc

NAME	=	libft.a
CC		=	gcc
AR 		=	ar rc
MK		=	mkdir -p
RM		=	rm -rvf

CFLAGS	 = -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	$(OBJS)
			${AR} ${NAME} ${OBJS}

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
				${CC} -I$(HDDIR) ${CFLAGS} -c $< -o $@

$(OBJDIR):
			@${MK} $@

clean:		;
			${RM} ${OBJDIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
