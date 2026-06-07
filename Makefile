NAME=retromfa
CC= cc
CFLAGS= -Wall -Wextra -Werror
SRCS= srcs/MFA.c
SRCS_OBJS= $(SRCS:.c=.o)
OS=$(shell uname)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(SRCS_OBJS)
ifeq ($(OS),Darwin)
	$(CC) $(CFLAGS) $(SRCS_OBJS) -o $(NAME)
else 
	$(CC) $(CFLAGS) $(SRCS_OBJS) -lbsd -o $(NAME)
endif

PATH=MFA/blue.mfa
run: $(NAME)
	./$(NAME) $(PATH)
clean: 
	rm -f $(SRCS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

COM=generique_com

git:
	git add .
	git commit -m  $(COM)
	git push origin $(shell git branch --show-current)

.PHONY: all $(NAME) clean fclean re