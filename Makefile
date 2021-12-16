CC = gcc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -L ./mlx -lmlx -framework OpenGL -framework AppKit

SRCS = ./src/ft_itoa.c ./src/get_next_line_utils.c ./src/get_next_line.c \
		./src/main.c ./src/map.c ./src/move.c ./src/utils.c ./src/utils_2.c
OBJS = $(SRCS:.c=.o)

NAME = so_long
BONUS = ./bonus_dir

all: $(NAME)

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MFLAGS)

bonus:
	make all -C $(BONUS)

clean:
	rm -f $(OBJS)
	make fclean -C $(BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
