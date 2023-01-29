/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:05:40 by admansar          #+#    #+#             */
/*   Updated: 2023/01/28 19:34:12 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

int	main(void)
{
	t_my_data my_data;
//	t_position pos;

	my_data.pos.x = 0;
	my_data.pos.y = 0;

   	my_data.ptr = mlx_init();
	my_data.win = mlx_new_window(my_data.ptr, 800, 800, "Mandelbrot");
	mandelbrot(my_data.ptr, my_data.win, my_data.pos, 680);
//	julia(680);
}
