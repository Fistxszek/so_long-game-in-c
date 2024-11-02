NAME = so_long

SRCS = so_long_main.c so_long_utils.c so_long_objects_utils.c so_long_map_utils.c so_long_close_utils.c so_long_draw_utils.c Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all