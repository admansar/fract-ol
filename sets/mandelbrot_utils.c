/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:55:43 by admansar          #+#    #+#             */
/*   Updated: 2023/02/05 14:16:56 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	boot_mandelbrot(t_my_data *my_data)
{
	my_data->pos.color = MANDELBROT_COLOR;
	my_data->ptr = mlx_init();
	my_data->win = mlx_new_window(my_data->ptr, TOOL, L3ARD, "Mandelbrot");
	mandelbrot(*my_data, BEGIN_POINT);
}
