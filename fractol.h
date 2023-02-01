/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:48:28 by admansar          #+#    #+#             */
/*   Updated: 2023/02/01 19:54:05 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/ft_printf.h"
# include "libft/libft.h"

# define TOOL 800
# define L3ARD 800
# define ITERATION 100
# define JULIA_COLOR 0xF0F0FF
# define MANDELBROT_COLOR 0xFFFFFF
# define BEGIN_POINT 600
# define LIMITS 22 * pow(10, 7)

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
}					t_complexe;

typedef struct position
{
	int x;
	int y;
	double down;
	double up;
	double rotation_reel;
	double rotation_imag;
	int color;
}					t_position;

typedef struct da_ta
{
	double			i;
	double			j;
	int				color;
	int				blasa;
	void			*ptr;
	void			*win;
	t_data			img;
	t_complexe		c;
	t_position		pos;
}					t_my_data;

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int magic(int key, t_my_data *my_data);
t_complexe			creat_lst(double a, double b);
t_complexe			somme(t_complexe a, t_complexe b);
t_complexe			produit(t_complexe a, t_complexe b);
t_complexe			*khwi(t_complexe *a);
void				rec_f(t_complexe z, t_complexe c, int *blasa);
void				proces_mandebrot(t_complexe z, int *blasa, t_complexe c,
						int *color, int *ss);
void				proces(t_complexe z, int *blasa, t_complexe c,
						int *color, int *ss);
int					funct(int key, t_my_data *my_data);
int					funct_j(int key, t_my_data *my_data);
void				fingerprint(t_my_data my_data);
void				mandelbrot(void *ptr, void *win, t_position pos,int u);
void				julia(t_my_data data,long int u);
int					mouse_hook(int key,int x, int y, t_my_data *my_data);
int					mouse_hook_j(int key,int x, int y, t_my_data *my_data);
int					magic_man(int key, t_my_data *my_data);
int					bye(t_my_data *my_data);

#endif
