/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:54:27 by toespino          #+#    #+#             */
/*   Updated: 2026/03/02 16:39:25 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(int32_t ac, char **av)
{
	t_mlx	mlx;
	double	*constants;

	(void)av;
	if (ac <= 1)
		error_message(1);
	av++;
	input_check(ac, av);
	constants = ft_calloc(2, sizeof(double));
	if (!constants)
		error_message(4);
	if (!ft_strncmp(av[0], "julia", ft_strlen(av[0])))
	{
		constants[0] = ft_atod(av[1]);
		constants[1] = ft_atod(av[2]);
	}
	mlx = better_mlx_init();
	mlx_key_hook(mlx.win, key_pressed, &mlx);
	mlx_hook(mlx.win, DestroyNotify, StructureNotifyMask, stop_loop, &mlx);
	mlx_loop(mlx.mlx);
	destroy_mlx(&mlx);
}
