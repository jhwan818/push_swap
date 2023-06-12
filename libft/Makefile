# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/06/12 23:25:20 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCDIR=.
OBJDIR=objs
SRCS=ft_abs.c                ft_lstlast_bonus.c      ft_strdup.c		\
	 ft_atoi.c               ft_lstmap_bonus.c       ft_striteri.c		\
	 ft_bzero.c              ft_lstnew_bonus.c       ft_strjoin.c		\
	 ft_calloc.c             ft_lstsize_bonus.c      ft_strlcat.c		\
	 ft_isalnum.c            ft_memchr.c             ft_strlcpy.c		\
	 ft_isalpha.c            ft_memcmp.c             ft_strlen.c		\
	 ft_isascii.c            ft_memcpy.c             ft_strmapi.c		\
	 ft_isdigit.c            ft_memmove.c            ft_strncmp.c		\
	 ft_isprint.c            ft_memset.c             ft_strnstr.c		\
	 ft_itoa.c               ft_putchar_fd.c         ft_strrchr.c		\
	 ft_lstadd_back_bonus.c  ft_putendl_fd.c         ft_strtrim.c		\
	 ft_lstadd_front_bonus.c ft_putnbr_fd.c          ft_substr.c		\
	 ft_lstclear_bonus.c     ft_putstr_fd.c          ft_tolower.c		\
	 ft_lstdelone_bonus.c    ft_split.c              ft_toupper.c		\
	 ft_lstiter_bonus.c      ft_strchr.c			 ft_max.c			\
	 ft_min.c				 ft_merge_sort.c		 ft_realloc.c		\
	 ft_str_isequal.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I.
AR=ar rcs
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
COMPILE.c=$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) Makefile
	$(AR) $@ $(OBJS)
	echo "(LIBFT) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile
	$(COMPILE.c) $@ $<
	echo "(LIBFT) COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

clean:
	rm -rfv $(OBJDIR)

fclean: clean
	rm -fv $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
