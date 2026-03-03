/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:28:43 by toespino          #+#    #+#             */
/*   Updated: 2026/03/03 19:56:37 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "c_libs.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define HEIGHT	1080
# define LENGTH 1080
# define WINDOW_NAME "Fract\'ol"
# define ZOOM_F 0.1
# define PRECISION 40
# define LIMIT 4

# define COLOR_1 0x000000
# define COLOR_2 0xffffff

# define ERROR "\e[31mError : \e[0m"
# define BAD_AC "Input must contain only fractal type and 2 floats for Julia\n"
# define MANDEL "mandelbrot do not take any parameters\n"
# define JULIA "julia need two floats as parameters\n"
# define MAL_ERR "failed memory allocation\n"
# define MLX_ERR "MLX failed\n"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int32_t	bpp;
	int32_t	ll;
	int32_t	e;
}	t_img;

typedef struct s_cplx
{
	double	r;
	double	i;
}	t_cplx;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	double	zoom;
	t_cplx	c;
	t_img	img;
	int32_t	type;
}	t_mlx;

void	better_mlx_init(t_mlx *mlx);
void	put_pixel(t_mlx *mlx, int32_t x, int32_t y, int32_t color);
void	push_image(t_mlx *mlx);
void	destroy_mlx(t_mlx *mlx);
int32_t	stop_loop(t_mlx *mlx);
int32_t	key_pressed(int32_t	keycode, t_mlx *mlx);
int32_t	mouse_input(int32_t mouse_button, int32_t x, int32_t y, t_mlx *mlx);

void	error_message(int32_t error_code);
void	input_check(int32_t ac, char **av);
double	ft_atod(char *input);

double	lerp(double unscaled, double new_min, double new_max, double old_max);
t_cplx	add_cplx(t_cplx c1, t_cplx c2);
t_cplx	square_cplx(t_cplx c);

void	draw_fractal(t_mlx *mlx);

#endif
