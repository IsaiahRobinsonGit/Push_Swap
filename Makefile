# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 13:49:52 by irobinso          #+#    #+#              #
#    Updated: 2025/01/09 04:01:25 by irobinso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable
NAME = push_swap

# Directories
SRCDIR = res
OBJDIR = obj
INCDIR = inc
LIBFTDIR = libraries/libft

# Source files
SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/input_check.c \
       $(SRCDIR)/push.c \
       $(SRCDIR)/ft_atol.c \
       $(SRCDIR)/rotate.c \
       $(SRCDIR)/reverse_rotate.c \
       $(SRCDIR)/swap.c \
       $(SRCDIR)/print_stacks.c \
       $(SRCDIR)/sorting.c

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT = $(LIBFTDIR)/libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFTDIR)/include

# Clean up command
RM = rm -f

# Build rules
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

# Valgrind target
valgrind: $(NAME)
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./$(NAME)

.PHONY: all clean fclean re valgrind
