NAME = fractol

CC = cc

CFLAGS = -I /usr/local/include/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror

SRC =  main.c mandelbrot/complexe_operations.c help.c mandelbrot/keys.c mandelbrot/mandelbrot.c mandelbrot/mandelbrot_utils.c mandelbrot/julia.c mandelbrot/julia_utils.c

all : $(NAME)

$(NAME) : 
	@echo "\033[1;36m"
	make -C libft yes
	@echo "\033[1;33m"
	$(CC) $(CFLAGS) libft/libft.a $(SRC) -o $(NAME)
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
