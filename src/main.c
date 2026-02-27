/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:54:27 by toespino          #+#    #+#             */
/*   Updated: 2026/02/27 21:38:12 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(int32_t ac, char **av)
{
	t_mlx	mlx;

	(void)av;
	if (ac <= 1 || ac >= 4)
		error_message(1);
	mlx = better_mlx_init();
	mlx_loop(mlx.mlx);
}
