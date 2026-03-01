/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 21:38:26 by toespino          #+#    #+#             */
/*   Updated: 2026/03/01 22:04:36 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(int32_t error_code)
{
	if (error_code == 1)
		write(2, ERROR BAD_AC, (ft_strlen(ERROR) + ft_strlen(BAD_AC)));
	else if (error_code == 2)
		write(2, ERROR MANDEL, (ft_strlen(ERROR) + ft_strlen(MANDEL)));
	else if (error_code == 3)
		write(2, ERROR JULIA, (ft_strlen(ERROR) + ft_strlen(JULIA)));
	else
		write(2, ERROR "What ?\n", (ft_strlen(ERROR) + 7));
	exit(error_code);
}

void	input_check(int32_t ac, char **av)
{
	if (ft_strncmp(av[0], "mandelbrot", ft_strlen(av[0])) == 0 && ac != 2)
		error_message(2);
	else if (ft_strncmp(av[0], "julia", ft_strlen(av[0])) == 0 && ac != 4)
		error_message(3);
}
