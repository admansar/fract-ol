NAME = fractol

CC = cc

CFLAGS = -I /usr/local/include/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : 
	@echo "\033[0;36m"
	$(CC) $(CFLAGS) main.c mandelbrot/complexe_operations.c mandelbrot/keys.c mandelbrot/mandelbrot.c mandelbrot/julia.c  -o $(NAME)
	@echo

clean :
	@echo
	@rm -rf $(NAME)
	@echo "\033[0;33mCleaned"
	@echo

fclean : clean

re : fclean all
