/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:02:32 by admansar          #+#    #+#             */
/*   Updated: 2023/02/05 20:06:56 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	etat_init(t_my_data *my_data, int o)
{
	my_data->pos.rotation_reel = 0;
	my_data->pos.rotation_imag = 0;
	my_data->pos.color = o;
	my_data->pos.x = 0;
	my_data->pos.y = 0;
}

int	funct(int key, t_my_data *my_data)
{
	static double	a;
	static double	b;
	static float	rest;

	escape(my_data, key);
	if ((key >= 123 && key <= 126) || key == 15)
	{
		rest = mouse_hook(0, my_data->pos.x, my_data->pos.y, my_data);
		in_or_out(key, &a, &b, rest);
		if (key == 15)
		{
			a = 0;
			b = 0;
			rest = 1;
			etat_init(my_data, MANDELBROT_COLOR);
		}
		my_data->pos.up = a;
		my_data->pos.down = b;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		mandelbrot(*my_data, rest + BEGIN_POINT);
	}
	return (rest);
}

int	mouse_hook(int key, int x, int y, t_my_data *my_data)
{
	static int	a;
	double		rest;

	rest = (double)a;
	(void)x;
	(void)y;
	if (a > LIMITS - BEGIN_POINT / 2)
	{
		a = a / 1.05;
		a = a - 50;
		return (a);
	}
	if (key == 5)
	{
		key_five(&a, my_data);
	}
	if (key == 4)
	{
		key_four(&a, my_data);
	}
	if (funct(0, my_data) == 1)
		a = 0;
	return (a);
}

void	live_man(t_my_data *my_data, char pm, char ir, double rest)
{
	if (pm == '+' && ir == 'r')
		my_data->pos.rotation_reel += 0.02;
	else if (pm == '-' && ir == 'r')
		my_data->pos.rotation_reel -= 0.02;
	else if (pm == '-' && ir == 'i')
		my_data->pos.rotation_imag -= 0.02;
	else if (pm == '+' && ir == 'i')
		my_data->pos.rotation_imag += 0.02;
	mlx_destroy_image(my_data->ptr, my_data->img.img);
	mlx_clear_window(my_data->ptr, my_data->win);
	mandelbrot(*my_data, rest + BEGIN_POINT);
}

int	magic_man(int key, t_my_data *my_data)
{
	double	rest;

	rest = mouse_hook(0, my_data->pos.x, my_data->pos.y, my_data);
	if (key == 69)
		live_man(my_data, '+', 'r', rest);
	if (key == 78)
		live_man(my_data, '-', 'r', rest);
	if (key == 75)
		live_man(my_data, '-', 'i', rest);
	if (key == 67)
		live_man(my_data, '+', 'i', rest);
	if (key == 8)
	{
		my_data->pos.color -= 500;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		mandelbrot(*my_data, rest + BEGIN_POINT);
	}
	return (rest);
}
