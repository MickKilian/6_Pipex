# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:34:29 by mbourgeo          #+#    #+#              #
#    Updated: 2022/08/17 04:59:58 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

PRIM_SRCS	=	main.c ft_pipex.c ft_exec.c ft_initialize.c ft_managerr.c \
				ft_redirect.c ft_freeclose.c ft_heredoc.c
PRIM_SRCDIR	=	prim/src
PRIM_PATH	=	$(addprefix $(PRIM_SRCDIR)/, $(PRIM_SRCS))
PRIM_OBJDIR	=	prim/obj
PRIM_OBJS	=	$(patsubst $(PRIM_SRCDIR)/%, $(PRIM_OBJDIR)/%, $(PRIM_PATH:.c=.o))

DEP_DIR		=	prim/dep
PRIM_DEP	=	$(patsubst $(PRIM_OBJDIR)/%.o, $(DEP_DIR)/%.d, $(PRIM_OBJS))

HEADER_SRCS	=	pipex.h
HEADER_DIR	=	prim/inc
HEADER_PATH	=	$(addprefix $(HEADER_DIR)/, $(HEADER_SRCS))

INCL_DIR	=	inc
NAME		=	pipex
LIB1_DIR	=	prim/lib/libft
LIB2_DIR	=	prim/lib/gnl
LIB1_NAME	=	libft.a
LIB2_NAME	=	libgnl.a
HDLIB1_DIR	=	$(LIB1_DIR)/inc
HDLIB2_DIR	=	$(LIB2_DIR)/inc
CC			=	cc
AR			=	ar rc
RM			=	rm -rvf
MK			=	mkdir -p
#DEBUG		=	-g3 -fsanitize=address
DEBUG		=	-fsanitize=address
CFLAGS		=	-Wall -Wextra -Werror
DFLAGS		=	-MMD -MF

#################################

all:		$(NAME)

bonus:			$(NAME)

$(NAME):	$(PRIM_OBJS) | $(LIB1_NAME) Makefile $(LIB2_NAME) Makefile
				$(CC) $(CFLAGS) $(DEBUG) $^ -I$(HEADER_DIR) -I$(HDLIB1_DIR) -I$(HDLIB2_DIR) -L$(LIB1_DIR) -lft -L$(LIB2_DIR) -lgnl -o $@

$(LIB1_NAME):
				$(MAKE) -C $(LIB1_DIR) all

$(LIB2_NAME):
				$(MAKE) -C $(LIB2_DIR) all

-include $(PRIM_DEP)
$(PRIM_OBJDIR)/%.o:		$(PRIM_SRCDIR)/%.c | $(LIB1_NAME) $(LIB2_NAME) $(PRIM_OBJDIR) $(DEP_DIR) $(HEADER_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(DEP_DIR)/$*.d -I$(HEADER_DIR) -I$(HDLIB1_DIR) -I$(HDLIB2_DIR) -c $< -o $@

$(PRIM_OBJDIR) $(DEP_DIR):		;
				@$(MK) $@

clean:		;
				@$(RM) $(PRIM_OBJDIR) $(DEP_DIR)

fclean:		clean
#				@$(RM) $(NAME) $(LIB1_NAME) $(LIB2_NAME)
				@$(RM) $(NAME)
				$(MAKE) -C $(LIB1_DIR) fclean
				$(MAKE) -C $(LIB2_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
