/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:34:07 by admansar          #+#    #+#             */
/*   Updated: 2023/01/24 20:42:58 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void    fingerprint_julia(t_my_data my_data, t_complexe c)
{
    mlx_put_image_to_window(my_data.ptr, my_data.win, my_data.img.img, 0, 0);
    mlx_key_hook(my_data.win, funct, &my_data);
    mlx_loop(my_data.ptr);
}

void    proces(t_complexe z, int *blasa, t_complexe c, int *color)
{
    z.reel = 0;
    z.imaginaire = 0;
    (*blasa) = 0;
    rec_f(z, c, blasa);
    (*color) = 0xFFFFFF * (*blasa);
    if ((*blasa) == 100)
        (*color) = 0;
}

void    julia(int x)
{
    t_my_data   my_data;
    t_complexe  z;
    t_complexe  c;

    my_data.i = -501;
    my_data.j = -500;
    z = creat_lst(0, 0);
    my_data.ptr = mlx_init();
    my_data.win = mlx_new_window(my_data.ptr, 1000, 1000, "Mandelbrot");
    my_data.img.img = mlx_new_image(my_data.ptr, 1920, 1080);
    my_data.img.addr = mlx_get_data_addr(my_data.img.img,
            &my_data.img.bits_per_pixel, &my_data.img.line_length,
            &my_data.img.endian);
            c = creat_lst(0, 0);
    while (my_data.i++ < 500)
    {
        my_data.j = -500;
        while (my_data.j < 500)
        {
            proces(z, &my_data.blasa, c, &my_data.color);
            my_mlx_pixel_put(&my_data.img, 500 + my_data.i, 500 - my_data.j++,
                my_data.color);
        }
    }
    fingerprint_julia(my_data, c);
}

