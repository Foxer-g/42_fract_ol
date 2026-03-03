/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:56:13 by toespino          #+#    #+#             */
/*   Updated: 2026/03/03 18:59:48 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	better_mlx_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		error_message(5);
	mlx->win = mlx_new_window(mlx->mlx, LENGTH, HEIGHT, WINDOW_NAME);
	if (!mlx->win)
	{
		free(mlx->mlx);
		error_message(5);
	}
	mlx->img.img = mlx_new_image(mlx->mlx, HEIGHT, LENGTH);
	if (!mlx->img.img)
	{
		free(mlx->mlx);
		free(mlx->win);
		error_message(5);
	}
	mlx->c.r = 0;
	mlx->c.i = 0;
	mlx->zoom = 1.0;
	mlx->type = 0;
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.ll,
			&mlx->img.e);
}

void	put_pixel(t_mlx *mlx, int32_t x, int32_t y, int32_t color)
{
	char	*dst;

	dst = mlx->img.addr + (y * mlx->img.ll + x * (mlx->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	push_image(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

void	destroy_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx = NULL;
}

int32_t	stop_loop(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx);
	return (0);
}
