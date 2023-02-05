/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:35:07 by admansar          #+#    #+#             */
/*   Updated: 2023/02/05 20:08:37 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	funct_j(int key, t_my_data *my_data)
{
	static double	a;
	static double	b;
	static float	rest;

	escape(my_data, key);
	if ((key >= 123 && key <= 126) || key == 15)
	{
		rest = mouse_hook_j(0, my_data->pos.x, my_data->pos.y, my_data);
		in_or_out(key, &a, &b, rest);
		if (key == 15)
		{
			a = 0;
			b = 0;
			rest = 1;
			etat_init(my_data, JULIA_COLOR);
		}
		my_data->pos.up = a;
		my_data->pos.down = b;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		julia(*my_data, rest + BEGIN_POINT / 2);
	}
	return (rest);
}

int	magic(int key, t_my_data *my_data)
{
	double	rest;

	rest = mouse_hook_j(0, my_data->pos.x, my_data->pos.y, my_data);
	if (key == 69)
		live(my_data, '+', 'r', rest);
	if (key == 78)
		live(my_data, '-', 'r', rest);
	if (key == 75)
		live(my_data, '-', 'i', rest);
	if (key == 67)
		live(my_data, '+', 'i', rest);
	if (key == 8)
	{
		my_data->pos.color -= 500;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		julia(*my_data, rest + BEGIN_POINT / 2);
	}
	return (rest);
}

int	mouse_hook_j(int key, int x, int y, t_my_data *my_data)
{
	static long int	a;
	double			rest;

	rest = (double)a;
	(void)x;
	(void)y;
	if (a > LIMITS - BEGIN_POINT / 2)
	{
		a = a / 1.05;
		a = a - 50;
		return (a);
	}
	if (key == 5 && a > -BEGIN_POINT / 2)
	{
		key_five_j(&a, my_data);
	}
	if (key == 4)
	{
		key_four_j(&a, my_data);
	}
	if (funct_j(0, my_data) == 1)
		a = 0;
	return (a);
}

void	key_five_j(long int *a, t_my_data *my_data)
{
	my_data->pos.color += 1;
	(*a) = (*a) + 50;
	if ((*a) + BEGIN_POINT / 2 > 500)
		(*a) = (*a) * 1.05;
	mlx_destroy_image(my_data->ptr, my_data->img.img);
	mlx_clear_window(my_data->ptr, my_data->win);
	julia(*my_data, (*a) + BEGIN_POINT / 2);
}

void	key_four_j(long int *a, t_my_data *my_data)
{
	my_data->pos.color -= 1;
	(*a) = (*a) - 50;
	if ((*a) + BEGIN_POINT / 2 > 500)
		(*a) = (*a) / 1.05;
	mlx_destroy_image(my_data->ptr, my_data->img.img);
	mlx_clear_window(my_data->ptr, my_data->win);
	if ((*a) < -BEGIN_POINT / 2)
		(*a) = -BEGIN_POINT / 2 + 1;
	julia(*my_data, (*a) + BEGIN_POINT / 2);
}
