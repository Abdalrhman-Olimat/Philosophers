CC		= cc
CFLAGS	= -Wall -Werror -Wextra -pthread 
NAME	= philo

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c input_error.c parsing.c init.c safe.c utils.c dinner.c write.c  synchro_utils.c getter_setter.c monitor.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS)  -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  -pthread $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
