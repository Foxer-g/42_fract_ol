/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:54:27 by toespino          #+#    #+#             */
/*   Updated: 2026/03/01 21:54:25 by toespino         ###   ########.fr       */
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

	mlx = better_mlx_init();
	mlx_hook(mlx.win, DestroyNotify, StructureNotifyMask, stop_loop, &mlx);
	mlx_loop(mlx.mlx);
	destroy_mlx(&mlx);
}
