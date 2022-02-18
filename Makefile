NAME := term3d
CC 	 := gcc
CFLAG := -Wall -Werror -Wextra
INCLUDE := term3d.h
SRCS :=	main.c \
		key_action.c \
		rotation.c
OBJS := $(SRCS:.c=.o)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAG)  -lm -c $< -o $@

all :$(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) -o $(NAME) $(CFLAG) $(OBJS) -lm

debug: $(OBJS) $(INCLUDE)
	$(CC) -o $(NAME) -g3 -fsanitize=address $(CFLAG) $(OBJS) -lm

clean:
	$(RM) $(OBJS)


fclean: clean
	$(RM) $(NAME)

re: fclean all
