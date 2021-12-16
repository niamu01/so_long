CC = gcc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -L ../mlx -lmlx -framework OpenGL -framework AppKit

SRCS = ../src/ft_itoa.c ../src/get_next_line_utils.c ../src/get_next_line.c ./main_bonus.c \
		 ./map_bonus.c ./move_bonus.c ./utils_bonus.c ./utils_2_bonus.c ./utils_3_bonus.c ./sub_main_bonus.c
OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MFLAGS)
	cp ./so_long ../

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
