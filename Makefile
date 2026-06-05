CC= cc
CFLAGS= -Wall -Wextra -Werror
SRCS= srcs/main.c
SRCS_OBJS= $(SRCS:.c=.o)


%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@