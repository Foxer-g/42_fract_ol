/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:29:49 by toespino          #+#    #+#             */
/*   Updated: 2026/03/02 20:21:32 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	lerp(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled / old_max + new_min);
}

t_cplx	add_cplx(t_cplx c1, t_cplx c2)
{
	t_cplx	res;

	res.r = c1.r + c2.r;
	res.i = c1.i + c2.i;
	return (res);
}

t_cplx	square_cplx(t_cplx c)
{
	t_cplx	res;

	res.r = (c.r * c.r) - (c.i * c.i);
	res.i = 2 * c.r * c.i;
	return (res);
}
