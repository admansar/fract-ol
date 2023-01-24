/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:48:28 by admansar          #+#    #+#             */
/*   Updated: 2023/01/24 02:48:30 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct complexe
{
	double			reel;
	double			imaginaire;
	struct complexe	*next;
}					t_complexe;

typedef struct my_data
{
	double			i;
	double			j;
	int				color;
	int				blasa;
	void			*ptr;
	void			*win;
	t_data			img;
}					t_my_data;

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_complexe			*creat_lst(double a, double b);
t_complexe			*somme(t_complexe *a, t_complexe *b);
t_complexe			*produit(t_complexe *a, t_complexe *b);
t_complexe			*khwi(t_complexe *a);
void				rec_f(t_complexe **z, t_complexe **c, int *blasa);
void				proces(t_complexe **z, int *blasa, t_complexe **c,
						int *color);
int					funct(int key, t_my_data *my_data);
void				fingerprint(t_my_data my_data);
void				mandelbrot(int x);

#endif
