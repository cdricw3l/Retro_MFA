NAME=retromfa
CC= cc
CFLAGS= -Wall -Wextra -Werror
SRCS= srcs/MFA.c
SRCS_OBJS= $(SRCS:.c=.o)


%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(CC) $(CFLAGS) $(SRCS_OBJS) -lbsd -o $(NAME)

clean: 
	rm -f $(SRCS_OBJS)

fclean: clean
	rm -f $(NAME) *.txt

re: fclean $(NAME)

COM=generique_com
git:
	git add .
	git commit -m  $(COM)
	git push origin $(shell git branch --show-current)

.PHONY: all $(NAME) clean fclean re