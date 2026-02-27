/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 21:38:26 by toespino          #+#    #+#             */
/*   Updated: 2026/02/27 21:45:02 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(int32_t error_code)
{
	if (error_code == 1)
		write(2, ERROR BAD_AC, (ft_strlen(ERROR) + ft_strlen(BAD_AC)));
	else
		write(2, ERROR "What ?\n", (ft_strlen(ERROR) + 7));
}
