/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:48:10 by toespino          #+#    #+#             */
/*   Updated: 2026/03/03 18:59:39 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	key_pressed(int32_t keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		stop_loop(mlx);
	return (0);
}

void	scroll_up(t_mlx *mlx)
{
	mlx->zoom /= (1.0 + ZOOM_F);
	draw_fractal(mlx);
}

void	scroll_down(t_mlx *mlx)
{
	mlx->zoom *= (1.0 + ZOOM_F);
	draw_fractal(mlx);
}

int32_t	mouse_input(int32_t mouse_button, int32_t x, int32_t y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (mouse_button == Button4)
		scroll_up(mlx);
	else if (mouse_button == Button5)
		scroll_down(mlx);
	return (0);
}
