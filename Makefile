# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:34:29 by mbourgeo          #+#    #+#              #
#    Updated: 2022/07/20 19:42:55 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

LIBFT_SRCS	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
				ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c ft_printf.c ft_printf_functions_1.c ft_printf_functions_2.c
LIB_SRCDIR	=	lib/libft/src
LIB_PATH	=	$(addprefix $(LIB_SRCDIR)/, $(LIBFT_SRCS))
LIB_OBJDIR	=	lib/libft/obj
LIB_OBJS	=	$(patsubst $(LIB_SRCDIR)/%, $(LIB_OBJDIR)/%, $(LIB_PATH:.c=.o))

PRIM_SRCS	=	main.c pipex.c ft_exec.c ft_filemanage.c
PRIM_SRCDIR	=	prim/src
PRIM_PATH	=	$(addprefix $(PRIM_SRCDIR)/, $(PRIM_SRCS))
PRIM_OBJDIR	=	prim/obj
PRIM_OBJS	=	$(patsubst $(PRIM_SRCDIR)/%, $(PRIM_OBJDIR)/%, $(PRIM_PATH:.c=.o))

DEP_DIR		=	prim/dep
PRIM_DEP	=	$(patsubst $(PRIM_OBJDIR)/%.o, $(DEP_DIR)/%.d, $(PRIM_OBJS))

HEADER_SRCS	=	pipex.h
HEADER_DIR	=	includes
HEADER_PATH	=	$(addprefix $(HEADER_DIR)/, $(HEADER_SRCS))

INCL_DIR	=	includes
NAME		=	pipex
LIB_NAME	=	libft.a
CC			=	cc
AR			=	ar rc
RM			=	rm -rvf
MK			=	mkdir -p
#DEBUG.....=	-g3 -fsanitize=address
CFLAGS		=	-Wall -Wextra -Werror
DFLAGS		=	-MMD -MF
#COPTIONS	=	-lXext -lX11 -lm
#CLIBS		=	-Ilib/mlx -Llib/mlx -lmlx_Linux

#################################

all:		$(NAME)

$(NAME):	$(PRIM_OBJS) | Makefile
#				$(CC) $^ $(CLIBS) -o $@ $(COPTIONS)
				$(CC) $^ -L. -lft -o $@

$(LIB_NAME):	${LIB_OBJS}
				${AR} ${LIB_NAME} ${LIB_OBJS}

$(LIB_OBJDIR)/%.o:	$(LIB_SRCDIR)/%.c| $(LIB_OBJDIR)
					${CC} ${CFLAGS} -c $< -o $@

-include $(PRIM_DEP)
$(PRIM_OBJDIR)/%.o:		$(PRIM_SRCDIR)/%.c | $(LIB_NAME) $(PRIM_OBJDIR) $(DEP_DIR) $(HEADER_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(DEP_DIR)/$*.d -c $< -o $@

$(PRIM_OBJDIR) $(DEP_DIR) $(LIB_OBJDIR):		;
				@$(MK) $@

clean:		;
				@$(RM) $(PRIM_OBJDIR) $(DEP_DIR) $(LIB_OBJDIR)

fclean:		clean
				@$(RM) $(NAME) $(LIB_NAME)

re:			fclean all

B_NAME.PHONY:		all clean fclean re
