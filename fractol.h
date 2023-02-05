/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:48:28 by admansar          #+#    #+#             */
/*   Updated: 2023/02/05 22:44:29 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define TOOL 800
# define L3ARD 800
# define ITERATION 100
# define JULIA_COLOR 0xF0F0FF
# define MANDELBROT_COLOR 0xFFFFFF
# define BEGIN_POINT 600
# define LIMITS 220000000

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_complexe
{
	double		reel;
	double		imaginaire;
}				t_complexe;

typedef struct s_position
{
	int			x;
	int			y;
	double		down;
	double		up;
	double		rotation_reel;
	double		rotation_imag;
	int			color;
}				t_position;

typedef struct s_da_ta
{
	double		i;
	double		j;
	int			color;
	int			blasa;
	void		*ptr;
	void		*win;
	t_data		img;
	t_complexe	c;
	t_complexe	z;
	t_position	pos;
}				t_my_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				magic(int key, t_my_data *my_data);
t_complexe		creat_lst(double a, double b);
t_complexe		somme(t_complexe a, t_complexe b);
t_complexe		produit(t_complexe a, t_complexe b);
t_complexe		*khwi(t_complexe *a);
void			rec_f(t_complexe z, t_complexe c, int *blasa);
void			proces_mandebrot(t_complexe z, t_complexe c, t_my_data *data);
void			proces(t_complexe z, t_complexe c, t_my_data *d);
int				funct(int key, t_my_data *my_data);
void			help(void);
int				funct_j(int key, t_my_data *my_data);
void			fingerprint(t_my_data my_data);
void			mandelbrot(t_my_data my_data, int u);
void			julia(t_my_data data, long int u);
int				mouse_hook(int key, int x, int y, t_my_data *my_data);
int				mouse_hook_j(int key, int x, int y, t_my_data *my_data);
int				magic_man(int key, t_my_data *my_data);
int				bye(t_my_data *my_data);
void			boot_mandelbrot(t_my_data *my_data);
void			boot_julia(t_my_data *my_data);
void			boot_burning_ship(t_my_data *my_data);
void			escape(t_my_data *my_data, int key);
void			in_or_out(int key, double *a, double *b, int rest);
void			etat_init(t_my_data *my_data, int o);
void			follow_x(int x, double rest, t_my_data *my_data);
void			follow_y(int y, double rest, t_my_data *my_data);
void			key_five(int *a, t_my_data *my_data);
void			key_five_j(long int *a, t_my_data *my_data);
void			key_four(int *a, t_my_data *my_data);
void			key_four_j(long int *a, t_my_data *my_data);
void			live(t_my_data *my_data, char pm, char ir, double rest);
void			burning_ship(t_my_data my_data, int alpha);
void			key_four_bs(int *a, t_my_data *my_data);
void			key_five_bs(int *a, t_my_data *my_data);
void			live_bs(t_my_data *my_data, char pm, char ir, double rest);
int				magic_bs(int key, t_my_data *my_data);
void			help_bonus(void);
int				mouse_hook_bs(int key, int x, int y, t_my_data *my_data);

#endif
