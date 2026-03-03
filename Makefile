CC = cc
CFLAGS = -Wall -Werror -Wextra -O3 -g 
NAME = fractol 
SRCDIR = src/
OBJDIR = build/
INCLUDE = -Iincludes -Ilibft/include
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -L.
LDLIBS = -lft -lXext -lX11

OBJ = main.o \
	utils.o \
	mlx_utils/window_utils.o\
	mlx_utils/input_management.o \
	draw_fractal.o \
	math.o \

OBJS = $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(OBJDIR):
	mkdir -p $@/mlx_utils/

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) libmlx.a  -o $@ $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	make -C $(LIBFT_DIR) -j

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFT_DIR) clean -j

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean -j

re: fclean
	make -C $(LIBFT_DIR) all -j
	make all

.PHONY: all clean fclean re
