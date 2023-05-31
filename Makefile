# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 22:00:29 by junghwle          #+#    #+#              #
#    Updated: 2023/05/31 13:50:49 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

SRCDIR=sources
DCLL_DIR=$(SRCDIR)/data_structure/dcll
STACK_DIR=$(SRCDIR)/data_structure/stack
PUSH_SWAP_DIR=$(SRCDIR)/push_swap
LIBFT_DIR=libft
FT_PRINTF_DIR=ft_printf

OBJDIR=objects
DCLL_SRC=ft_dcll_add.c	ft_dcll_clear.c	ft_dcll_init.c	ft_dcll_newnode.c	\
		 ft_dcll_peek.c	ft_dcll_pop.c
STACK_SRC=ft_stack.c ft_stack2.c
PUSH_SWAP_SRC=ps_action.c			ps_push.c			ps_reverse_rotate.c	\
			  ps_rotate.c			ps_swap.c			ps_parse_input.c	\
			  ps_show_stack.c		ps_sort.c			push_swap.c			\
			  ps_console.c
LIBFT_SRC=ft_atoi.c					ft_bzero.c			ft_calloc.c			\
	  	  ft_isalnum.c				ft_isalpha.c		ft_isascii.c		\
		  ft_isdigit.c				ft_isprint.c	  	ft_itoa.c			\
		  ft_memchr.c				ft_memcmp.c			ft_memcpy.c			\
		  ft_memmove.c				ft_memset.c			ft_putchar_fd.c		\
		  ft_putendl_fd.c			ft_putnbr_fd.c		ft_putstr_fd.c		\
		  ft_split.c				ft_strchr.c			ft_strdup.c			\
		  ft_striteri.c				ft_strjoin.c		ft_strlcat.c		\
		  ft_strlcpy.c				ft_strlen.c			ft_strmapi.c		\
		  ft_strncmp.c				ft_strnstr.c		ft_strrchr.c		\
		  ft_strtrim.c				ft_substr.c			ft_tolower.c		\
		  ft_toupper.c				ft_lstnew_bonus.c						\
		  ft_lstadd_front_bonus.c	ft_lstsize_bonus.c	ft_lstlast_bonus.c	\
		  ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c					\
		  ft_lstclear_bonus.c		ft_lstiter_bonus.c	ft_lstmap_bonus.c	\
		  ft_abs.c
FT_PRINTF_SRC=ft_print_format_bonus.c		ft_putstr_bonus.c				\
			  ft_printf_bonus.c				ft_putchar_bonus.c				\
			  ft_getdecimal_bonus.c			ft_gethexa_low_bonus.c			\
			  ft_gethexa_up_bonus.c			ft_getinteger_bonus.c			\
			  ft_getpointer_bonus.c			ft_getstr_bonus.c				\
		   	  ft_getudecimal_bonus.c		ft_hltoa_bonus.c				\
		   	  ft_hutoa_bonus.c				ft_htoa_base_bonus.c			\
		   	  ft_utoa_bonus.c				ft_parse_format_bonus.c			\
		   	  ft_getmin_bonus.c				ft_getmax_bonus.c				\
		   	  ft_sign_control_bonus.c		ft_fill_zero.c
DCLL_OBJ=$(patsubst %.c, $(OBJDIR)/%.o, $(DCLL_SRC))
STACK_OBJ=$(patsubst %.c, $(OBJDIR)/%.o, $(STACK_SRC))
PUSH_SWAP_OBJ=$(patsubst %.c, $(OBJDIR)/%.o, $(PUSH_SWAP_SRC))
LIBFT_OBJ=$(patsubst %.c, $(OBJDIR)/%.o, $(LIBFT_SRC))
FT_PRINTF_OBJ=$(patsubst %.c, $(OBJDIR)/%.o, $(FT_PRINTF_SRC))
OBJS=$(DCLL_OBJ) $(STACK_OBJ) $(PUSH_SWAP_OBJ) $(LIBFT_OBJ) $(FT_PRINTF_OBJ)

CC=cc
FLAGS=-Wall -Werror -Wextra -Iheaders

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)
	echo "CREATE $@"

$(OBJDIR)/%.o: $(DCLL_DIR)/%.c
	$(CC) $(FLAGS) -c -o $@ $<
	echo "COMPILING (DCLL) $@"

$(OBJDIR)/%.o: $(STACK_DIR)/%.c
	$(CC) $(FLAGS) -c -o $@ $<
	echo "COMPILING (STACK) $@"

$(OBJDIR)/%.o: $(PUSH_SWAP_DIR)/%.c
	$(CC) $(FLAGS) -c -o $@ $<
	echo "COMPILING (PUSH_SWAP) $@"

$(OBJDIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(FLAGS) -c -o $@ $<
	echo "COMPILING (LIBFT) $@"

$(OBJDIR)/%.o: $(FT_PRINTF_DIR)/%.c
	$(CC) $(FLAGS) -c -o $@ $<
	echo "COMPILING (FT_PRINTF) $@"

$(OBJDIR):
	mkdir -p $(OBJDIR)

test: all
	./$(NAME) 1 5 4 3 7 8 2 6 9 10

clean:
	rm -fv *.c
	rm -fv *.h
	rm -rfv $(OBJDIR)

fclean: clean
	rm -fv $(NAME)

re: fclean all

push: fclean
	git add .
	git commit -m "update"
	git push

.PHONY: all clean fclean re test push
.SILENT:
