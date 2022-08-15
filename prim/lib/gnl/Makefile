# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 22:04:39 by mbourgeo          #+#    #+#              #
#    Updated: 2022/08/15 21:42:46 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

SRCS	=	get_next_line.c get_next_line_utils.c
SRCDIR	=	src
LB_PATH	=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJDIR	=	obj
OBJS	=	$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(LB_PATH:.c=.o))
HDDIR	=	inc

NAME	=	libgnl.a
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
