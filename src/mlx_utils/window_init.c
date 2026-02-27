/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:56:13 by toespino          #+#    #+#             */
/*   Updated: 2026/02/27 04:58:13 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

t_mlx	mlx_init(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, HEIGHT, LENGHT, WINDOW_NAME);
	mlx.img.img = mlx_new_image(mlx.mlx, HEIGHT, LENGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bpp, &mlx.img.ll,
		&mlx.img.e);
	return (mlx);
}

void	put_pixel(t_mlx mlx, int32_t x, int32_t y, int32_t color)
{
	char	*dst;

	dst = mlx.img->addr + (y * mlx.img->ll + x * (mlx.img.dpp / 8));
	*(unsigned int*)dst = color;
}

void	push_image(t_mlx mlx)
{
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
}
