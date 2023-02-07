/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:43:48 by admansar          #+#    #+#             */
/*   Updated: 2023/02/07 08:34:18 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	live(t_my_data *my_data, char pm, char ir, double rest)
{
	if (pm == '+' && ir == 'r')
		my_data->pos.rotation_reel += 0.02;
	else if (pm == '-' && ir == 'r')
		my_data->pos.rotation_reel -= 0.02;
	else if (pm == '-' && ir == 'i')
		my_data->pos.rotation_imag -= 0.02;
	else if (pm == '+' && ir == 'i')
		my_data->pos.rotation_imag += 0.02;
	mlx_destroy_image(my_data->ptr, my_data->img.img);
	mlx_clear_window(my_data->ptr, my_data->win);
	julia(*my_data, rest + BEGIN_POINT / 2);
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

void	in_or_out(int key, double *a, double *b, float rest)
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
