/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:54:27 by toespino          #+#    #+#             */
/*   Updated: 2026/03/03 17:24:14 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(int32_t ac, char **av)
{
	t_mlx	mlx;

	(void)av;
	if (ac <= 1)
		error_message(1);
	av++;
	input_check(ac, av);
	better_mlx_init(&mlx);
	if (!ft_strncmp(av[0], "julia", ft_strlen(av[0])))
	{
		mlx.c.r = ft_atod(av[1]);
		mlx.c.i = ft_atod(av[2]);
		mlx.type = 2;
	}
	draw_fractal(&mlx);
	mlx_key_hook(mlx.win, key_pressed, &mlx);
	mlx_mouse_hook(mlx.win, mouse_input, &mlx);
	mlx_hook(mlx.win, DestroyNotify, StructureNotifyMask, stop_loop, &mlx);
	mlx_loop(mlx.mlx);
	destroy_mlx(&mlx);
}
