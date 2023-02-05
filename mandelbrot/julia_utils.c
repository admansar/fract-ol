/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:03:24 by admansar          #+#    #+#             */
/*   Updated: 2023/02/04 23:13:32 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	boot_julia(t_my_data *my_data)
{
	my_data->pos.color = JULIA_COLOR;
	my_data->ptr = mlx_init();
	my_data->win = mlx_new_window(my_data->ptr, TOOL, L3ARD, "Julia");
	julia(*my_data, BEGIN_POINT / 2);
}
