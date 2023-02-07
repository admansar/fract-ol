/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:55:43 by admansar          #+#    #+#             */
/*   Updated: 2023/02/07 08:47:35 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	boot_burning_ship(t_my_data *my_data)
{
	my_data->pos.color = 0x00FFFF;
	my_data->ptr = mlx_init();
	my_data->win = mlx_new_window(my_data->ptr, TOOL, L3ARD, "bs");
	burning_ship(*my_data, BEGIN_POINT);
}

void	key_five_bs(int *a, t_my_data *my_data)
{
	my_data->pos.color += 2;
	(*a) = (*a) + 50;
	if ((*a) + BEGIN_POINT > 2000)
		(*a) = (*a) * 1.05;
	mlx_destroy_image(my_data->ptr, my_data->img.img);
	mlx_clear_window(my_data->ptr, my_data->win);
	burning_ship(*my_data, (*a) + BEGIN_POINT);
}

void	key_four_bs(int *a, t_my_data *my_data)
{
	my_data->pos.color -= 2;
	(*a) = (*a) - 50;
	if ((*a) + BEGIN_POINT > 2000)
		(*a) = (*a) / 1.05;
	mlx_destroy_image(my_data->ptr, my_data->img.img);
	mlx_clear_window(my_data->ptr, my_data->win);
	if ((*a) < -BEGIN_POINT)
		(*a) = -BEGIN_POINT;
	burning_ship(*my_data, (*a) + BEGIN_POINT);
}
