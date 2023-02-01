/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:02:32 by admansar          #+#    #+#             */
/*   Updated: 2023/02/01 19:53:41 by admansar         ###   ########.fr       */
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
			my_data->pos.rotation_reel = 0;
			my_data->pos.rotation_imag = 0;
			my_data->pos.color = MANDELBROT_COLOR;
			my_data->pos.x = 0;
			my_data->pos.y = 0;
		
		}
		my_data->pos.up = a;
		my_data->pos.down = b;
//		my_data->pos.x = 0;
//		my_data->pos.y = 0;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        mandelbrot(my_data->ptr, my_data->win, my_data->pos, rest + BEGIN_POINT);
	}
	return (rest);
}

int mouse_hook(int key,int x, int y, t_my_data *my_data)
{
    static int a;
    int d;
	double rest;

	rest = (double)a;
	if (a > LIMITS - BEGIN_POINT/2)
	{
		a = a / 1.05;
		a = a - 50;
		return (a);
	}
    d = BEGIN_POINT;
//	printf("x = %d\ny = %d\na + d ========> %d\n", my_data->pos.x, my_data->pos.y, a + d);
    if (key == 5)
    {
		my_data->pos.color+=2;
		if (x - L3ARD/3 < 0)
		{
			if(rest <= 2000)
			my_data->pos.up -= 0.04;
			else 
				my_data->pos.up -= (50 / rest);
		}
		else if (x -(2 * L3ARD/3) > 0)
		{
			if(rest <= 2000)
			my_data->pos.up += 0.04;
			else 
				my_data->pos.up += (50/ rest);
		}
			if (TOOL/3 > y)
				{
					if (rest <= 2000)
					my_data->pos.down += 0.04;
					else 
						my_data->pos.down += (50 / rest);
//					my_data->pos.down *= 0.8;
				}
			else if ((2 * TOOL/3) < y)
			{
				if (rest <= 2000)
				my_data->pos.down -= 0.04;
				else
					my_data->pos.down -= (50 / rest);
//				my_data->pos.down *= 0.8;
			}
        a = a + 50;
		if ( a + d > 2000)
			a = a * 1.05;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        mandelbrot(my_data->ptr, my_data->win, my_data->pos, a + d);
     }
    if (key == 4)
    {
	my_data->pos.color-=2;
        a = a - 50;
		if ( a + d > 2000)
			a = a / 1.05;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		if (a < -BEGIN_POINT)
			a = -BEGIN_POINT;
		mandelbrot(my_data->ptr, my_data->win, my_data->pos, a + d);
	}
	if (funct(0, my_data) == 1)
		a = 0;
    return (a);
}

int	funct_j(int key, t_my_data *my_data)
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
		rest = mouse_hook_j(0, my_data->pos.x, my_data->pos.y, my_data);
	//	printf("rest ==>%f\n",rest);
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
			my_data->pos.rotation_reel = 0;
			my_data->pos.rotation_imag = 0;
			my_data->pos.color = JULIA_COLOR;
			my_data->pos.x = 0;
			my_data->pos.y = 0;
		}
	//	printf("a===>%f\n", a);
		my_data->pos.up = a;
		my_data->pos.down = b;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        julia(*my_data, rest + BEGIN_POINT/2);
	}
//	printf("%d\n", key);
	return (rest);
}

int magic(int key, t_my_data *my_data)
{
	double rest;

	rest = mouse_hook_j(0, my_data->pos.x, my_data->pos.y, my_data);
	if (key == 69)
	{
		my_data->pos.rotation_reel += 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        julia(*my_data, rest + BEGIN_POINT/2);
	}
	if (key == 78)
	{
		my_data->pos.rotation_reel -= 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        julia(*my_data, rest + BEGIN_POINT/2);
	}
	if (key == 75)
	{
		my_data->pos.rotation_imag -= 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        julia(*my_data, rest + BEGIN_POINT/2);
	}
	if (key == 67)
	{
		my_data->pos.rotation_imag += 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        julia(*my_data, rest + BEGIN_POINT/2);
	}
	if (key == 8)
	{
		my_data->pos.color -= 500;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        julia(*my_data, rest + BEGIN_POINT/2);
	}
//	printf("%d\n", key);
	return (rest);
}

int mouse_hook_j(int key,int x, int y, t_my_data *my_data)
{
    static long int a;
	double rest;
	
	rest = (double)a;
	if (a > LIMITS - BEGIN_POINT/2)
	{
		a = a / 1.05;
		a = a - 50;
		return (a);
	}
//	printf("lr = %f--------up = %f\n", my_data->pos.down, my_data->pos.up);
//	printf("--->%f\n", rest);
    if (key == 5 && a > -BEGIN_POINT / 2)
    {
	my_data->pos.color+=1;
		if (x - L3ARD/3 < 0)
		{
			if(rest <= 2000)
			my_data->pos.up -= 0.04;
			else 
				my_data->pos.up -= (50 / rest);
		}
		else if (x -(2 * L3ARD/3) > 0)
		{
			if(rest <= 2000)
			my_data->pos.up += 0.04;
			else 
				my_data->pos.up += (50/ rest);
		}
			if (TOOL/3 > y)
				{
					if (rest <= 2000)
					my_data->pos.down += 0.04;
					else 
						my_data->pos.down += (50 / rest);
//					my_data->pos.down *= 0.8;
				}
			else if ((2 * TOOL/3) < y)
			{
				if (rest <= 2000)
				my_data->pos.down -= 0.04;
				else
					my_data->pos.down -= (50 / rest);
//				my_data->pos.down *= 0.8;
			}
        a = a + 50;
		if ( a + BEGIN_POINT / 2 > 500)
			a = a * 1.05;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        julia(*my_data, a + BEGIN_POINT / 2);
     }
    if (key == 4)
    {
	my_data->pos.color-=1;
        a = a - 50;
		if ( a + BEGIN_POINT/2 > 500)
			a = a / 1.05;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
		if (a < -BEGIN_POINT/2)
			a = -BEGIN_POINT/2 + 1;
		julia(*my_data, a + BEGIN_POINT / 2);
	}
	if (funct_j(0, my_data) == 1)
		a = 0;
    return (a);
}

int magic_man(int key, t_my_data *my_data)
{
	double rest;

	rest = mouse_hook(0, my_data->pos.x, my_data->pos.y, my_data);
	if (key == 69)
	{
		my_data->pos.rotation_reel += 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        mandelbrot(my_data->ptr, my_data->win, my_data->pos, rest + BEGIN_POINT);
	}
	if (key == 78)
	{
		my_data->pos.rotation_reel -= 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        mandelbrot(my_data->ptr, my_data->win, my_data->pos, rest + BEGIN_POINT);
	}
	if (key == 75)
	{
		my_data->pos.rotation_imag -= 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        mandelbrot(my_data->ptr, my_data->win, my_data->pos, rest + BEGIN_POINT);
	}
	if (key == 67)
	{
		my_data->pos.rotation_imag += 0.02;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        mandelbrot(my_data->ptr, my_data->win, my_data->pos, rest + BEGIN_POINT);
	}
	if (key == 8)
	{
		my_data->pos.color -= 500;
		mlx_destroy_image(my_data->ptr, my_data->img.img);
		mlx_clear_window(my_data->ptr, my_data->win);
        mandelbrot(my_data->ptr, my_data->win, my_data->pos, rest + BEGIN_POINT);
	}
//	printf("%d\n", key);
	return (rest);
}

int bye(t_my_data *my_data)
{
	mlx_destroy_image(my_data->ptr, my_data->img.img);
	mlx_destroy_window(my_data->ptr, my_data->win);
	exit(0);
}
