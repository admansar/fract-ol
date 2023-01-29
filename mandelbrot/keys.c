/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:02:32 by admansar          #+#    #+#             */
/*   Updated: 2023/01/29 17:45:56 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <time.h>

int	funct(int key, t_my_data *my_data)
{
	static double	a;
	static double	b;
	static double	c;
	static float	rest;

	if (key == 53)
	{
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_destroy_window(my_data->ptr, my_data->win);
		exit(0);
	}
	if ((key >= 123 && key <= 126) || key == 15)
	{
		rest = mouse_hook(0, my_data->pos.x, my_data->pos.y, my_data);
		if (rest <= 2000)
		{
			if (key == 124)
				a = a + 0.1;
			else if ( key == 123)
				a = a - 0.1;
			else if (key == 126)
				b = b + 0.1;
			else if (key == 125)
				b = b - 0.1;
		}
		else
		{
			if (key == 123)
				a = a - (100 / rest);
			if (key == 124)
				a = a + (100 / rest);
			if (key ==126)
				b = b + (100 / rest);
			if (key == 125)
				b = b - (100 / rest);
		}
		if (key == 15)
		{
			a = 0;
			b = 0;
			rest = 1;
		}
		my_data->pos.up = a;
		my_data->pos.down = b;
//		my_data->pos.x = 0;
//		my_data->pos.y = 0;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        mandelbrot(my_data->ptr, my_data->win, my_data->pos, rest + 680);
	}
	return (rest);
}

int mouse_hook(int key,int x, int y, t_my_data *my_data)
{
    static int a;
    int d;

    d = 680;
//	printf("x = %d\ny = %d\na + d ========> %d\n", my_data->pos.x, my_data->pos.y, a + d);
    if (key == 5)
    {
        a = a + 50;
		if ( a + d > 2000)
			a = a * 1.1;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        mandelbrot(my_data->ptr, my_data->win, my_data->pos, a + d);
     }
    if (key == 4)
    {
        a = a - 50;
		if ( a + d > 2000)
			a = a / 1.1;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		if (a < -680)
			a = -680;
		mandelbrot(my_data->ptr, my_data->win, my_data->pos, a + d);
	}
	if (funct(0, my_data) == 1)
		a = 0;
    return (a);
}

