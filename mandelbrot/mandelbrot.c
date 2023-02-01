/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:11:29 by admansar          #+#    #+#             */
/*   Updated: 2023/02/01 19:55:31 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	proces_mandelbrot(t_complexe z, int *blasa, t_complexe c, int *color, int *pos_col)
{
	t_complexe	pro;

	z.reel = 0;
	z.imaginaire = 0;
	(*blasa) = 0;
	while (z.reel * z.imaginaire <= 4 && (*blasa) < ITERATION)
	{
		pro.reel = z.reel * z.reel - z.imaginaire * z.imaginaire;
		pro.imaginaire = 2 * z.reel * z.imaginaire;
		z.reel = pro.reel + c.reel;
		z.imaginaire = pro.imaginaire + c.imaginaire;
		(*blasa)++;
	}
	(*color) = (*pos_col) * (*blasa);
	if ((*blasa) == ITERATION)
		(*color) = 0;
}

#include <time.h>
void	fingerprint(t_my_data my_data)
{
	
	mlx_put_image_to_window(my_data.ptr, my_data.win, my_data.img.img, 0, 0);
	mlx_key_hook(my_data.win, funct, &my_data);
	mlx_mouse_hook(my_data.win, mouse_hook, &my_data);
	mlx_hook(my_data.win, 2, 0, magic_man, &my_data);
	mlx_hook(my_data.win, 17, 0, bye, &my_data);
	mlx_loop(my_data.ptr);
}

void	mandelbrot(void *ptr, void *win, t_position pos,int alpha)
{
	t_my_data	my_data;
	t_complexe	z;
	t_complexe	c;

	my_data.i = -TOOL/2;
	my_data.j = -L3ARD/2;
	z.reel = 0;
	z.imaginaire = 0;
	my_data.pos = pos;
	my_data.ptr = ptr;
	my_data.win = win;
	my_data.img.img = mlx_new_image(my_data.ptr, 1920, 1080);
	my_data.img.addr = mlx_get_data_addr(my_data.img.img,
			&my_data.img.bits_per_pixel, &my_data.img.line_length,
			&my_data.img.endian);
	while (my_data.i++ < TOOL/2)
	{
		my_data.j = -L3ARD/2;
		while (my_data.j < L3ARD/2)
		{
			c.reel = pos.up + ((2 * my_data.i - TOOL/2 + pos.x) / alpha);
		    c.imaginaire = pos.down + ((2 * my_data.j + pos.y) / alpha);
			proces_mandelbrot(z, &my_data.blasa, c, &my_data.color, &my_data.pos.color);
			my_mlx_pixel_put(&my_data.img, TOOL/2 + my_data.i, L3ARD/2 - my_data.j++,
				my_data.color);
		}
	}
	fingerprint(my_data);
}
