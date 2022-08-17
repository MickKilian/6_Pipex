# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:34:29 by mbourgeo          #+#    #+#              #
#    Updated: 2022/08/17 16:58:40 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

PRIM_SRCS	=	main.c ft_pipex.c ft_exec.c ft_initialize.c ft_managerr.c \
				ft_redirect.c ft_freeclose.c
PRIM_SRCDIR	=	prim/src
PRIM_PATH	=	$(addprefix $(PRIM_SRCDIR)/, $(PRIM_SRCS))
PRIM_OBJDIR	=	prim/obj
PRIM_OBJS	=	$(patsubst $(PRIM_SRCDIR)/%, $(PRIM_OBJDIR)/%, $(PRIM_PATH:.c=.o))

BONUS_SRCS	=	main_bonus.c ft_pipex_bonus.c ft_exec_bonus.c ft_initialize_bonus.c \
				ft_managerr_bonus.c ft_redirect_bonus.c ft_freeclose_bonus.c \
				ft_heredoc_bonus.c
BONUS_SRCDIR	=	bonus/src
BONUS_PATH	=	$(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCS))
BONUS_OBJDIR	=	bonus/obj
BONUS_OBJS	=	$(patsubst $(BONUS_SRCDIR)/%, $(BONUS_OBJDIR)/%, $(BONUS_PATH:.c=.o))

PR_DEP_DIR		=	prim/dep
PRIM_DEP	=	$(patsubst $(PRIM_OBJDIR)/%.o, $(PR_DEP_DIR)/%.d, $(PRIM_OBJS))
BN_DEP_DIR		=	bonus/dep
BONUS_DEP	=	$(patsubst $(BONUS_OBJDIR)/%.o, $(BN_DEP_DIR)/%.d, $(BONUS_OBJS))

HEADER_SRCS	=	pipex.h
HEADER_DIR	=	prim/inc
HEADER_PATH	=	$(addprefix $(HEADER_DIR)/, $(HEADER_SRCS))
BN_HD_SRCS	=	pipex_bonus.h
BN_HD_DIR	=	bonus/inc
BN_HD_PATH	=	$(addprefix $(BN_HD_DIR)/, $(BN_HD_SRCS))

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
CFLAGS		=	-Wall -Wextra -Werror
DFLAGS		=	-MMD -MF

#################################

all:		$(NAME)

$(NAME):	$(PRIM_OBJS) | $(LIB1_NAME) Makefile $(LIB2_NAME) Makefile
				$(CC) $(CFLAGS) $(DEBUG) $^ -I$(HEADER_DIR) -I$(HDLIB1_DIR) -I$(HDLIB2_DIR) -L$(LIB1_DIR) -lft -L$(LIB2_DIR) -lgnl -o $@

bonus:		$(BONUS_OBJS) | $(LIB1_NAME) Makefile $(LIB2_NAME) Makefile
				$(CC) $(CFLAGS) $(DEBUG) $^ -I$(BN_HD_DIR) -I$(HDLIB1_DIR) -I$(HDLIB2_DIR) -L$(LIB1_DIR) -lft -L$(LIB2_DIR) -lgnl -o $(NAME)

$(LIB1_NAME):
				$(MAKE) -C $(LIB1_DIR) all

$(LIB2_NAME):
				$(MAKE) -C $(LIB2_DIR) all

-include $(PRIM_DEP)
$(PRIM_OBJDIR)/%.o:		$(PRIM_SRCDIR)/%.c | $(LIB1_NAME) $(LIB2_NAME) $(PRIM_OBJDIR) $(PR_DEP_DIR) $(HEADER_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(PR_DEP_DIR)/$*.d -I$(HEADER_DIR) -I$(HDLIB1_DIR) -I$(HDLIB2_DIR) -c $< -o $@

$(PRIM_OBJDIR) $(PR_DEP_DIR):		;
				@$(MK) $@

$(BONUS_OBJDIR)/%.o:		$(BONUS_SRCDIR)/%.c | $(LIB1_NAME) $(LIB2_NAME) $(BONUS_OBJDIR) $(BN_DEP_DIR) $(HEADER_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(BN_DEP_DIR)/$*.d -I$(BN_HD_DIR) -I$(HDLIB1_DIR) -I$(HDLIB2_DIR) -c $< -o $@

$(BONUS_OBJDIR) $(BN_DEP_DIR):		;
				@$(MK) $@

clean:		;
				@$(RM) $(PRIM_OBJDIR) $(PR_DEP_DIR)
				@$(RM) $(BONUS_OBJDIR) $(BN_DEP_DIR)

fclean:		clean
				@$(RM) $(NAME)
				$(MAKE) -C $(LIB1_DIR) fclean
				$(MAKE) -C $(LIB2_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
