
NAME =		fractol

MLX_DIR = 	./minilibx_mms_20200219

MLX_LIB	=	-L$(MLX_DIR) -lmlx

INCLUDES =	-I$(MLX_DIR)

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra

SRCS =		main.c \
		validation.c \
		mandelbrot.c \
		julia.c \
		aux_fts.c \
		hooks.c \
		libft/ft_putcolor_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_strncmp.c \
		libft/ft_atoi.c \
		libft/ft_strdup.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c

OBJS =		${SRCS:.c=.o} 

RM =		rm -f

.c.o:
			$(CC) $(CFLAGS) $(INCLUDES)  -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			make -C $(MLX_DIR)
			cp $(MLX_DIR)/libmlx.dylib .
			$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
