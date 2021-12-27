SRCS	=	a_to_b.c \
			b_to_a.c \
			check_arg.c \
			delete.c \
			find_pivot.c \
			free_stack.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstnew.c \
			ft_lstprelast.c \
			ft_lstsize.c \
			ft_memcpy.c \
			ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			init_stack.c \
			place_last_elem.c \
			push_swap.c \
			sort_small.c \
			sort_stack_size_3.c \
			stack_ops_a.c \
			stack_ops_b.c 

NAME	= push_swap

OBJS	= $(SRCS:.c=.o)

OBJS_D	=$(patsubst %.c,%.d,$(SRCS))

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -MD

include $(wildcard $(OBJS_D))

clean:
	$(RM) $(OBJS) $(OBJS_D)

fclean:	clean
	$(RM) $(NAME)

re: 	fclean all
	
.PHONY: all clean fclean re bonus