/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:05:40 by admansar          #+#    #+#             */
/*   Updated: 2023/02/01 18:05:49 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

int	main(int ac, char **av)
{
	t_my_data my_data;
//	t_position pos;
//

	my_data.pos.x = 0;
	my_data.pos.y = 0;
	if (ac > 1 && ac <= 5 && ac != 3)
	{
	if (ft_strncmp(av[1], "Mandelbrot", ft_strlen("Mandelbrot") + 1) == 0)
	{
		my_data.pos.color = MANDELBROT_COLOR;
		my_data.ptr = mlx_init();
		my_data.win = mlx_new_window(my_data.ptr, TOOL, L3ARD, "Mandelbrot");
		mandelbrot(my_data.ptr, my_data.win, my_data.pos, BEGIN_POINT);
	}
	else if (ft_strncmp(av[1], "Julia", ft_strlen("Julia") + 1) == 0)
	{
		if (ac == 2)
		{
			my_data.pos.color = JULIA_COLOR;
			my_data.ptr = mlx_init();
			my_data.c.reel = 0.27;
			my_data.c.imaginaire = 0;
			my_data.win = mlx_new_window(my_data.ptr, TOOL, L3ARD, "Julia");
			julia(my_data, BEGIN_POINT/2);
		}
		else if (ac == 4)
		{
			my_data.c.reel = ft_atof(av[2]);
			my_data.c.imaginaire = ft_atof(av[3]);
			if ((my_data.c.reel >= -2 && my_data.c.reel <= 2 ) && (my_data.c.imaginaire >= -2 && my_data.c.imaginaire <= 2))
			{
				my_data.pos.color = JULIA_COLOR;
				my_data.ptr = mlx_init();
				my_data.win = mlx_new_window(my_data.ptr, TOOL, L3ARD, "Julia");
				julia(my_data, BEGIN_POINT/2);
			}
		}
	}
	}
	ft_printf("\033[4;31m             _______________________________________________            \033[0m");
		ft_printf("\n\n\n so that's the fractol project \n and this is \033[1;37mTHE MINI HELP\033[0m\nif you see it that's mean that you're strugling ... broo i'll give you some hunts\nso to see mandelbrot set print \033[1;32mMandelbrot \033[0mand if you want to see julia set then print \033[1;32mJulia \033[0m\n\033[1;31mkeep in mind:\033[4;31m if you need an exact set for julia print two float numbers after Julia \033[47mbetwen 2 and -2\033[0m \n\n                                 have fun ;)\n\n\n\n");
	ft_printf("\033[4;31m               _______________________________________________            \n");
}
