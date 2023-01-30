/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:05:40 by admansar          #+#    #+#             */
/*   Updated: 2023/01/30 22:58:26 by admansar         ###   ########.fr       */
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
	if (ac > 1 && ac <= 5)
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
			my_data.win = mlx_new_window(my_data.ptr, TOOL, L3ARD, "Julia");
			julia(my_data.ptr, my_data.win, my_data.pos, BEGIN_POINT/2);
		}
		else if (ac == 4)
		{
			my_data.pos.color = JULIA_COLOR;
			my_data.ptr = mlx_init();
			my_data.win = mlx_new_window(my_data.ptr, TOOL, L3ARD, "Julia");
			julia(my_data.ptr, my_data.win, my_data.pos, BEGIN_POINT/2);
		}
	}
	}
		ft_printf("\n\n\n so that's the fractol project \n and this is \033[1;37mTHE MINI HELP\033[0m\nif you se it that's mean that you're strugling ... broo i'll give you some hunts\nso to see mandelbrot set print \033[1;32mMandelbrot \033[0mand if you want to see julia set then print \033[1;32mJulia \033[0m\n\033[4;31mkeep in mind: if you need an exact set for julia print two float numbers after Julia and have fun ;)\n\n\n\n");
}
