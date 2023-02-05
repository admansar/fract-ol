/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:02:32 by admansar          #+#    #+#             */
/*   Updated: 2023/02/05 15:44:24 by admansar         ###   ########.fr       */
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

void	follow_x(int x, double rest, t_my_data *my_data);
void	follow_y(int y, double rest, t_my_data *my_data);
void	key_five(int *a, t_my_data *my_data);
void	key_five_j(long int *a, t_my_data *my_data);
int	mouse_hook(int key, int x, int y, t_my_data *my_data)
{
	static int	a;
	double		rest;

	rest = (double)a;
	if (a > LIMITS - BEGIN_POINT / 2)
	{
		a = a / 1.05;
		a = a - 50;
		return (a);
	}
	if (key == 5)
	{
		key_five(&a, my_data)
	}
	if (key == 4)
	{
		my_data->pos.color -= 2;
		a = a - 50;
		if (a + BEGIN_POINT > 2000)
			a = a / 1.05;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		if (a < -BEGIN_POINT)
			a = -BEGIN_POINT;
		mandelbrot(*my_data, a + BEGIN_POINT);
	}
	if (funct(0, my_data) == 1)
		a = 0;
	return (a);
}

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
	{
		my_data->pos.rotation_reel += 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		julia(*my_data, rest + BEGIN_POINT / 2);
	}
	if (key == 78)
	{
		my_data->pos.rotation_reel -= 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		julia(*my_data, rest + BEGIN_POINT / 2);
	}
	if (key == 75)
	{
		my_data->pos.rotation_imag -= 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		julia(*my_data, rest + BEGIN_POINT / 2);
	}
	if (key == 67)
	{
		my_data->pos.rotation_imag += 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		julia(*my_data, rest + BEGIN_POINT / 2);
	}
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
	if (a > LIMITS - BEGIN_POINT / 2)
	{
		a = a / 1.05;
		a = a - 50;
		return (a);
	}
	if (key == 5 && a > -BEGIN_POINT / 2)
	{
		follow_x(x, rest, my_data);
		follow_y(y, rest, my_data);
		key_five_j(&a, my_data);
	}
	if (key == 4)
	{
		my_data->pos.color -= 1;
		a = a - 50;
		if (a + BEGIN_POINT / 2 > 500)
			a = a / 1.05;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		if (a < -BEGIN_POINT / 2)
			a = -BEGIN_POINT / 2 + 1;
		julia(*my_data, a + BEGIN_POINT / 2);
	}
	if (funct_j(0, my_data) == 1)
		a = 0;
	return (a);
}

int	magic_man(int key, t_my_data *my_data)
{
	double	rest;

	rest = mouse_hook(0, my_data->pos.x, my_data->pos.y, my_data);
	if (key == 69)
	{
		my_data->pos.rotation_reel += 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		mandelbrot(*my_data, rest + BEGIN_POINT);
	}
	if (key == 78)
	{
		my_data->pos.rotation_reel -= 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		mandelbrot(*my_data, rest + BEGIN_POINT);
	}
	if (key == 75)
	{
		my_data->pos.rotation_imag -= 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		mandelbrot(*my_data, rest + BEGIN_POINT);
	}
	if (key == 67)
	{
		my_data->pos.rotation_imag += 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		mandelbrot(*my_data, rest + BEGIN_POINT);
	}
	if (key == 8)
	{
		my_data->pos.color -= 500;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		mandelbrot(*my_data, rest + BEGIN_POINT);
	}
	return (rest);
}

int	bye(t_my_data *my_data)
{
	mlx_destroy_image(my_data->ptr, my_data->img.img);
	mlx_destroy_window(my_data->ptr, my_data->win);
	exit(0);
}

void	escape(t_my_data *my_data, int key)
{
	if (key == 53)
	{
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_destroy_window(my_data->ptr, my_data->win);
		exit(0);
	}
}
void	in_or_out(int key, double *a, double *b, int rest)
{
	if (rest <= 2000)
	{
		if (key == 124)
			(*a) = (*a) + 0.1;
		else if (key == 123)
			(*a) = (*a) - 0.1;
		else if (key == 126)
			(*b) = (*b) + 0.1;
		else if (key == 125)
			(*b) = (*b) - 0.1;
	}
	else
	{
		if (key == 123)
			(*a) = (*a) - (100 / rest);
		if (key == 124)
			(*a) = (*a) + (100 / rest);
		if (key == 126)
			(*b) = (*b) + (100 / rest);
		if (key == 125)
			(*b) = (*b) - (100 / rest);
	}
}
void	follow_x(int x, double rest, t_my_data *my_data)
{
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
}

void	follow_y(int y, double rest, t_my_data *my_data)
{
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
void	key_five(int *a, t_my_data *my_data)
{
	my_data->pos.color += 2;
	(*a) = (*a) + 50;
	if ((*a) + BEGIN_POINT > 2000)
		(*a) = (*a) * 1.05;
	mlx_destroy_image(my_data->ptr, my_data->img.img);
	mlx_clear_window(my_data->ptr, my_data->win);
	mandelbrot(*my_data, a + BEGIN_POINT);
}
