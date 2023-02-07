/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:46:00 by admansar          #+#    #+#             */
/*   Updated: 2023/02/07 01:43:06 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	follow_x(int x, double rest, t_my_data *my_data)
{
	double	tmp;

	tmp = my_data->pos.up;
	if (x - L3ARD / 3 < 0)
	{
		if (rest <= 2000)
			my_data->pos.up -= 0.04;
		else
			my_data->pos.up -= (50 / rest);
	}
	else if (x - (2 * L3ARD / 3) > 0)
	{
		if (rest <= 2000)
			my_data->pos.up += 0.04;
		else
			my_data->pos.up += (50 / rest);
	}
	return (my_data->pos.up - tmp);
}

double	follow_y(int y, double rest, t_my_data *my_data)
{
	double	tmp;

	tmp = my_data->pos.down;
	if (TOOL / 3 > y)
	{
		if (rest <= 2000)
			my_data->pos.down += 0.04;
		else
			my_data->pos.down += (50 / rest);
	}
	else if ((2 * TOOL / 3) < y)
	{
		if (rest <= 2000)
			my_data->pos.down -= 0.04;
		else
			my_data->pos.down -= (50 / rest);
	}
	return (my_data->pos.down - tmp);
}

void	key_five(int *a, t_my_data *my_data)
{
	my_data->pos.color += 2;
	(*a) = (*a) + 50;
	if ((*a) + BEGIN_POINT > 2000)
		(*a) = (*a) * 1.05;
	mlx_destroy_image(my_data->ptr, my_data->img.img);
	mlx_clear_window(my_data->ptr, my_data->win);
	mandelbrot(*my_data, (*a) + BEGIN_POINT);
}

void	key_four(int *a, t_my_data *my_data)
{
	my_data->pos.color -= 2;
	(*a) = (*a) - 50;
	if ((*a) + BEGIN_POINT > 2000)
		(*a) = (*a) / 1.05;
	mlx_destroy_image(my_data->ptr, my_data->img.img);
	mlx_clear_window(my_data->ptr, my_data->win);
	if ((*a) < -BEGIN_POINT)
		(*a) = -BEGIN_POINT;
	mandelbrot(*my_data, (*a) + BEGIN_POINT);
}
