/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 21:38:26 by toespino          #+#    #+#             */
/*   Updated: 2026/03/02 15:46:07 by toespino         ###   ########.fr       */
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

void	ft_isdouble(char *input)
{
	int32_t	i;

	i = 0;
	while (input[i] && ft_isspace(input[i]))
		i++;
	while (input[i] && ft_issignednum(input[i]))
		i++;
	if (!input[i])
		return ;
	else if (input[i] == '.')
		i++;
	else
		error_message(3);
	while (input[i] && ft_isdigit(input[i]))
		i++;
	if (input[i])
		error_message(3);
}

void	input_check(int32_t ac, char **av)
{
	if (ft_strncmp(av[0], "mandelbrot", ft_strlen(av[0])) == 0 && ac != 2)
		error_message(2);
	else if (ft_strncmp(av[0], "julia", ft_strlen(av[0])) == 0 && ac != 4)
		error_message(3);
	else if (ft_strncmp(av[0], "julia", ft_strlen(av[0])) == 0 && ac == 4)
	{
		ft_isdouble(av[1]);
		ft_isdouble(av[2]);
	}
}

double	ft_atod(char *input)
{
	double	res;
	double	p_comma;
	int32_t	sign;
	int32_t	i;

	res = 0;
	sign = 1;
	i = 0;
	p_comma = 0.1;
	while (ft_isspace(input[i]))
		i++;
	if (input[i] == '-' || input[i] == '+')
	{
		if (input[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(input[i]))
		res = res * 10 + input[i++] - 48;
	while (input[i] && ft_isdigit(input[i]))
	{
		res += p_comma * (input[i++] - 48);
		p_comma /= 10;
	}
	return (res * sign);
}
