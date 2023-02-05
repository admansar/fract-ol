/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:11:29 by admansar          #+#    #+#             */
/*   Updated: 2023/02/05 22:44:45 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	proces_bs(t_complexe z, t_complexe c, t_my_data *data)
{
	t_complexe	pro;

	z.reel = 0;
	z.imaginaire = 0;
	data->blasa = 0;
	while (z.reel * z.imaginaire <= 4 && data->blasa < ITERATION)
	{
		pro.reel = z.reel * z.reel - z.imaginaire * z.imaginaire;
		pro.imaginaire = 2 * z.reel * z.imaginaire;
		z.reel = fabs(pro.reel + c.reel);
		z.imaginaire = fabs(pro.imaginaire + c.imaginaire);
		data->blasa++;
	}
	data->color = data->pos.color * data->blasa;
	if (data->blasa == ITERATION)
		data->color = 0;
}

void	fingerprint_bs(t_my_data my_data)
{
	mlx_put_image_to_window(my_data.ptr, my_data.win, my_data.img.img, 0, 0);
	mlx_key_hook(my_data.win, funct, &my_data);
	mlx_mouse_hook(my_data.win, mouse_hook_bs, &my_data);
	mlx_hook(my_data.win, 2, 0, magic_bs, &my_data);
	mlx_hook(my_data.win, 17, 0, bye, &my_data);
	mlx_loop(my_data.ptr);
}

void	burning_ship(t_my_data my_data, int alpha)
{
	t_complexe	c;

	my_data.i = -TOOL / 2;
	my_data.j = -L3ARD / 2;
	my_data.img.img = mlx_new_image(my_data.ptr, 1920, 1080);
	my_data.img.addr = mlx_get_data_addr(my_data.img.img,
			&my_data.img.bits_per_pixel,
			&my_data.img.line_length,
			&my_data.img.endian);
	while (my_data.i++ < TOOL / 2)
	{
		my_data.j = -L3ARD / 2;
		while (my_data.j < L3ARD / 2)
		{
			c.reel = my_data.pos.up + ((2 * my_data.i - TOOL / 2
						+ my_data.pos.x) / alpha);
			c.imaginaire = my_data.pos.down + ((2 * my_data.j
						+ my_data.pos.y) / alpha);
			proces_bs(my_data.z, c, &my_data);
			my_mlx_pixel_put(&my_data.img, TOOL / 2 + my_data.i,
				L3ARD / 2 - my_data.j++, my_data.color);
		}
	}
	fingerprint_bs(my_data);
}
