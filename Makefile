NAME=retromfa
CC= cc
CFLAGS= -Wall -Wextra -Werror
SRCS= srcs/MFA.c
SRCS_OBJS= $(SRCS:.c=.o)


%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(CC) $(CFLAGS) $(SRCS_OBJS) -o $(NAME)

clean: 
	rm -f $(SRCS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all $(NAME) clean fclean re