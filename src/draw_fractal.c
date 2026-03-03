/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:19:20 by toespino          #+#    #+#             */
/*   Updated: 2026/03/03 18:19:52 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_fractal_pixel(t_mlx *mlx, int32_t x, int32_t y)
{
	t_cplx	pixel;
	int32_t	i;
	int32_t	color;

	pixel.r = (lerp(x, -2, 2, LENGTH) * mlx->zoom);
	pixel.i = (lerp(y, 2, -2, HEIGHT) * mlx->zoom);
	if (mlx->type == 0)
		mlx->c = pixel;
	i = 0;
	while (i < PRECISION)
	{
		pixel = add_cplx(square_cplx(pixel), mlx->c);
		if ((pixel.r * pixel.r) + (pixel.i * pixel.i) > LIMIT)
		{
			color = lerp(i, COLOR_1, COLOR_2, PRECISION);
			put_pixel(mlx, x, y, color);
			return ;
		}
		i++;
	}
	put_pixel(mlx, x, y, COLOR_2);
}

void	draw_fractal(t_mlx *mlx)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	y = 0;
	while (x < LENGTH)
	{
		while (y < HEIGHT)
		{
			calculate_fractal_pixel(mlx, x, y);
			y++;
		}
		x++;
		y = 0;
	}
	push_image(mlx);
}
