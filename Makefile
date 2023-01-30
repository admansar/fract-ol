NAME = fractol

CC = cc

CFLAGS = -I /usr/local/include/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : 
	@echo "\033[1;36m"
	make -C libft yes
	@echo "\033[1;33m"
	$(CC) $(CFLAGS) main.c mandelbrot/complexe_operations.c libft/libft.a mandelbrot/keys.c mandelbrot/mandelbrot.c mandelbrot/julia.c  -o $(NAME)
	@echo

clean :
	@echo
	@rm -rf $(NAME)
	@echo "\033[0;33mCleaned"
	@echo

fclean : clean
	@rm -rf libft/libft.a
	@echo "\033[0;33mPerfectly"

re : fclean all
