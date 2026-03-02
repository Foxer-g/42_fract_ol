/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:56:13 by toespino          #+#    #+#             */
/*   Updated: 2026/03/02 20:46:50 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	better_mlx_init(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.c.r = 0;
	mlx.c.i = 0;
	mlx.zoom = 1.0;
	mlx.type = 0;
	mlx.win = mlx_new_window(mlx.mlx, LENGHT, HEIGHT, WINDOW_NAME);
	mlx.img.img = mlx_new_image(mlx.mlx, HEIGHT, LENGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bpp, &mlx.img.ll,
			&mlx.img.e);
	return (mlx);
}

void	put_pixel(t_mlx mlx, int32_t x, int32_t y, int32_t color)
{
	char	*dst;

	dst = mlx.img.addr + (y * mlx.img.ll + x * (mlx.img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	push_image(t_mlx mlx)
{
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
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

int32_t mouse_input(int32_t	mouse_button, t_mlx *mlx)
{
	if (mouse_button == Button4)
		scroll_up(mlx);
	else if (mouse_button == Button5)
		scroll_down(mlx);
	return (0);
}
