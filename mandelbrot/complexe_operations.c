/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexe_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:57:37 by admansar          #+#    #+#             */
/*   Updated: 2023/01/24 20:39:49 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complexe	creat_lst(double a, double b)
{
	t_complexe	ada;

	ada.reel = a;
	ada.imaginaire = b;
	return (ada);
}

t_complexe	somme(t_complexe a, t_complexe b)
{
	return (creat_lst(a.reel + b.reel, b.imaginaire + a.imaginaire));
}

t_complexe	produit(t_complexe a, t_complexe b)
{
	double	a1;
	double	a2;
	double	b1;
	double	b2;

	a1 = a.reel;
	a2 = a.imaginaire;
	b2 = b.imaginaire;
	b1 = b.reel;
	return (creat_lst((a1 * b1) - (a2 * b2), (a1 * b2) + (a2 * b1)));
}

t_complexe	*khwi(t_complexe *a)
{
	a->reel = 0;
	a->imaginaire = 0;
	return (a);
}
