/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:34:07 by admansar          #+#    #+#             */
/*   Updated: 2023/01/31 22:49:50 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void    fingerprint_julia(t_my_data my_data)
{
	mlx_put_image_to_window(my_data.ptr, my_data.win, my_data.img.img, 0, 0);
	mlx_key_hook(my_data.win, funct_j, &my_data);
	mlx_mouse_hook(my_data.win, mouse_hook_j, &my_data);
	mlx_hook(my_data.win, 2, 0, magic, &my_data);
	mlx_loop(my_data.ptr);
}

void    proces(t_complexe z, int *blasa, t_complexe c, int *color, int *pos_color)
{
    (*blasa) = 0;
 	t_complexe	pro;

//	printf("c =>%f----------%f\n", c.reel, c.imaginaire);

	while ((*blasa) < ITERATION)
	{
		pro.reel = z.reel * z.reel - z.imaginaire * z.imaginaire;
		pro.imaginaire = 2 * z.reel * z.imaginaire;
		z.reel = pro.reel + c.reel;
		z.imaginaire = pro.imaginaire + c.imaginaire;	
//	printf("z=>%f----------%f\n", z.reel, z.imaginaire);
		(*blasa)++;
		if ((z.reel*z.reel) + (z.imaginaire*z.imaginaire)>= 4)
			break ;
	}
//	printf("%d\n",(*blasa));
    (*color) = (*pos_color) * (*blasa);
    if ((*blasa) == ITERATION)
        (*color) = 0;
}

void    julia(t_my_data my_data, long int x)
{
//    t_my_data   my_data;
    t_complexe  z;
    t_complexe  c;

    my_data.i = -(TOOL/2);
    my_data.j = -(L3ARD/2);
//	printf("%ld\n", x);
//    z = creat_lst(0, 0);
 //   my_data.pos = pos;
 //   my_data.ptr = ptr;
//	my_data.win= win;
    my_data.img.img = mlx_new_image(my_data.ptr, 1920, 1080);
    my_data.img.addr = mlx_get_data_addr(my_data.img.img,
            &my_data.img.bits_per_pixel, &my_data.img.line_length,
            &my_data.img.endian);
	c.reel = my_data.c.reel + my_data.pos.rotation_reel;
	c.imaginaire = my_data.c.imaginaire + my_data.pos.rotation_imag;
    while (my_data.i++ < TOOL/2)
    {
        my_data.j = -L3ARD/2;
        while (my_data.j < L3ARD/2)
        {
			z.reel = my_data.pos.up + (my_data.i + my_data.pos.x) / x;
			z.imaginaire = my_data.pos.down + (my_data.j + my_data.pos.y) / x;
            proces(z, &my_data.blasa, c, &my_data.color, &my_data.pos.color);
            my_mlx_pixel_put(&my_data.img, TOOL/2 + my_data.i, L3ARD/2 - my_data.j++,
                my_data.color);
//			c.reel = 0;
//			c.imaginaire = 0;
        }
    }
    fingerprint_julia(my_data);
}

