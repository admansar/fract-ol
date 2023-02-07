/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:05:40 by admansar          #+#    #+#             */
/*   Updated: 2023/02/07 09:04:13 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int ac, char **av)
{
	t_my_data	my_data;

	my_data.pos.x = 0;
	my_data.pos.y = 0;
	if (ac > 1 && ac <= 5 && ac != 3)
	{
		if (ft_strncmp(av[1], "Mandelbrot", ft_strlen("Mandelbrot") + 1) == 0
			&& ac == 2)
			boot_mandelbrot(&my_data);
		else if (ft_strncmp(av[1], "bs", ft_strlen("bs") + 1) == 0 && ac == 2)
			boot_burning_ship(&my_data);
		else if (ft_strncmp(av[1], "Julia", ft_strlen("Julia") + 1) == 0
			&& ac == 4)
		{
			if (guard(av[2]) == 0 && guard(av[3]) == 0)
			{
				my_data.c.reel = ft_atof(av[2]);
				my_data.c.imaginaire = ft_atof(av[3]);
				if (my_data.c.reel >= -2 && my_data.c.reel <= 2
					&& my_data.c.imaginaire >= -2 && my_data.c.imaginaire <= 2)
					boot_julia(&my_data);
			}
		}
	}
	help_bonus();
}
