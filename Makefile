NAME = fractol

NAME_B = fractol_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -I /usr/local/include/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRC =  main.c guard.c  sets/complexe_operations.c help.c sets/julia_keys.c sets/mandelbrot_keys.c sets/mandelbrot.c sets/mandelbrot_utils.c sets/julia.c sets/julia_utils.c sets/keys_utils1.c sets/keys_utils.c

SRC_B = bonus/help_bonus.c guard.c bonus/main_bonus.c bonus/complexe_operations.c help.c bonus/julia_keys.c bonus/mandelbrot_key.c bonus/mandelbrot.c bonus/mandelbrot_utils.c bonus/julia.c bonus/julia_utils.c bonus/keys_utils1.c bonus/keys_utils.c bonus/burning_ship.c bonus/burning_ship_key.c bonus/burning_ship_utils.c

OBJ_B = ${SRC_B:.c=.o}

B = bonus

LIBFT = libft/libft.a

HEADER = fractol.h

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	@echo "\033[1;36m"
	@make -C libft
	@echo "\033[1;33m"
	$(CC) $(CFLAGS) $(MLXFLAGS) libft/libft.a $(SRC) -o $(NAME)
	@echo

$(B) : $(OBJ_B) $(HEADER)
	@echo 
	@echo "\033[1;36m"
	@make -C libft
	@echo "\033[1;33m"
	$(CC) $(CFLAGS) $(MLXFLAGS) libft/libft.a $(OBJ_B) -o $(NAME_B)

$(LIBFT):
	make -C libft

clean :
	@echo
	@rm -f *.o && rm -f bonus/*.o && rm -f sets/*.o
	make -C libft clean
	@echo "\033[0;33mCleaned"
	@echo

nothing :

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@echo "\033[0;33mPerfectly"

re : fclean all

re_bonus : fclean bonus

