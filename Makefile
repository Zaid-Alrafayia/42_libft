# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 02:08:29 by zaalrafa          #+#    #+#              #
#    Updated: 2026/01/11 11:25:33 by zaalrafa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -I.
AR      = ar rcs
RM      = rm -f

# --- Mandatory Sources (libft, printf, gnl) ---
SRCS =  ascii/ft_isalnum.c ascii/ft_isalpha.c ascii/ft_isascii.c \
        ascii/ft_isdigit.c ascii/ft_isprint.c \
        convert/ft_atoi.c convert/ft_itoa.c convert/hexconvert.c \
        convert/point_conv.c \
        math/ft_abs.c \
        mem/ft_bzero.c mem/ft_calloc.c mem/ft_memchr.c mem/ft_memcmp.c \
        mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memset.c \
        put/ft_putchar_fd.c put/ft_putendl_fd.c put/ft_putnbr_fd.c \
        put/ft_putstr_fd.c put/print_num.c put/print_str.c \
        put/print_unum.c \
        str/ft_split.c str/ft_strchr.c str/ft_strdup.c str/ft_striteri.c \
        str/ft_strjoin.c str/ft_strlcat.c str/ft_strlcpy.c str/ft_strlen.c \
        str/ft_strmapi.c str/ft_strncmp.c str/ft_strnstr.c str/ft_strrchr.c \
        str/ft_strtrim.c str/ft_substr.c str/ft_tolower.c str/ft_toupper.c \
        printf/ft_printf.c \
        gnl/get_next_line.c gnl/get_next_line_utils.c lst/ft_lstadd_back_bonus.c lst/ft_lstadd_front_bonus.c \
         lst/ft_lstclear_bonus.c lst/ft_lstdelone_bonus.c \
         lst/ft_lstiter_bonus.c lst/ft_lstlast_bonus.c \
         lst/ft_lstmap_bonus.c lst/ft_lstnew_bonus.c \
         lst/ft_lstsize_bonus.c \
         gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c
				lst/ft_lstmax.c lst/ft_lstmin.c

# --- Object File Generation ---
OBJS    = $(SRCS:.c=.o)
OBJS_B  = $(SRCS_B:.c=.o)

# Default Rule
all: $(NAME)

# Compile the Static Library
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Bonus Rule (Compiles everything including linked lists)
bonus: $(OBJS) $(OBJS_B)
	$(AR) $(NAME) $(OBJS) $(OBJS_B)

# Standard Compilation Rule
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup Rules
clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
