NAME = fractol

NAME_B = fractol_bonus

CC = cc

CFLAGS = -I /usr/local/include/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror

SRC =  main.c sets/complexe_operations.c help.c sets/julia_keys.c sets/mandelbrot_keys.c sets/mandelbrot.c sets/mandelbrot_utils.c sets/julia.c sets/julia_utils.c sets/keys_utils1.c sets/keys_utils.c

SRC_B = bonus/help_bonus.c bonus/main_bonus.c bonus/complexe_operations.c help.c bonus/julia_keys.c bonus/mandelbrot_key.c bonus/mandelbrot.c bonus/mandelbrot_utils.c bonus/julia.c bonus/julia_utils.c bonus/keys_utils1.c bonus/keys_utils.c bonus/burning_ship.c bonus/burning_ship_key.c bonus/burning_ship_utils.c

B = bonus

all : $(NAME)

$(NAME) : 
	@echo "\033[1;36m"
	make -C libft yes
	@echo "\033[1;33m"
	$(CC) $(CFLAGS) libft/libft.a $(SRC) -o $(NAME)
	@echo

$(B) : clean 
	@echo 
	@echo "\033[1;36m"
	make -C libft yes
	@echo "\033[1;33m"
	$(CC) $(CFLAGS) libft/libft.a $(SRC_B) -o $(NAME_B)

clean :
	@echo
	@rm -f $(NAME)
	@rm -f $(NAME_B) 
	@echo "\033[0;33mCleaned"
	@echo

fclean : clean
	@rm -rf libft/libft.a
	@echo "\033[0;33mPerfectly"

re : fclean all

re_bonus : fclean bonus
