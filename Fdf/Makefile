NAME = fdf
SRCS		=	atoi.c \
			draw_tools.c \
			fdf.c \
			ft_split.c \
			get_next_line_utils.c \
			get_next_line.c \
			hooks.c \
			read_map.c \
			utils.c \
			views.c \
			utils2.c 
OBJS = $(SRCS:.c=.o)
INCS = fdf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IMLX	= -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) -o ${NAME} $(CFLAGS) $(OBJS) $(IMLX)

%.o: %.c $(INCS)
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f fdf

re: fclean all

.PHONY: all bonus clean fclean re