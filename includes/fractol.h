/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:28:43 by toespino          #+#    #+#             */
/*   Updated: 2026/02/27 22:15:29 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H
# include "c_libs.h"
# include "mlx.h"

# define HEIGHT	1080
# define LENGHT 1920
# define WINDOW_NAME "Fract\'ol"
# define ERROR "\e[31mError : \e[0m"
# define BAD_AC "Input must contain only fractal type and coordinates for Julia"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int32_t	bpp;
	int32_t	ll;
	int32_t	e;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

t_mlx	better_mlx_init(void);
void	put_pixel(t_mlx mlx, int32_t x, int32_t y, int32_t color);
void	push_image(t_mlx mlx);

void	error_message(int32_t error_code);

#endif
