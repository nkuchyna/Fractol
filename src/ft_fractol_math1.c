/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_math1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:48:18 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/05/20 19:20:29 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_image *img)
{
	double		z_real;
	double		z_img;
	double		tmp;

	z_real = 0;
	z_img = 0;
	while (z_real * z_real + z_img * z_img < 4 && ++img->count_iter < ITER_NBR)
	{
		tmp = z_real * z_real - z_img * z_img + img->c_real;
		z_img = 2 * z_real * z_img + img->c_img;
		z_real = tmp;
	}
	img->zn = sqrt(z_img * z_img + z_real * z_real);
}

void	ft_julia(t_image *img)
{
	double		z_real;
	double		z_img;
	double		tmp;

	z_real = img->c_real;
	z_img = img->c_img;
	while (z_real * z_real + z_img * z_img < 4 && ++img->count_iter < ITER_NBR)
	{
		tmp = z_real * z_real - z_img * z_img - img->real_p;
		z_img = 2 * z_real * z_img + img->img_p;
		z_real = tmp;
	}
	img->zn = sqrt(z_img * z_img + z_real * z_real);
}

void	ft_burning_ship(t_image *img)
{
	double		z_real;
	double		z_img;
	double		tmp;

	z_real = 0;
	z_img = 0;
	while (z_real * z_real + z_img * z_img < 4 && ++img->count_iter < ITER_NBR)
	{
		tmp = z_real * z_real - z_img * z_img + img->c_real;
		z_img = 2 * fabs(z_real * z_img) + img->c_img;
		z_real = tmp;
	}
	img->zn = sqrt(z_img * z_img + z_real * z_real);
}

void	ft_flower(t_image *img)
{
	double		z_real;
	double		z_img;
	double		tmp;

	z_real = img->c_real;
	z_img = img->c_img;
	while (z_real * z_real + z_img * z_img < 4 && ++img->count_iter < ITER_NBR)
	{
		tmp = fabs(z_real * z_real - z_img * z_img) - 0.68015;
		z_img = 2 * fabs(z_real * z_img) + 0.30303;
		z_real = tmp;
	}
	img->zn = sqrt(z_img * z_img + z_real * z_real);
}

void	ft_beetle(t_image *img)
{
	double		z_real;
	double		z_img;
	double		tmp;
	double		c_real;
	double		c_img;

	z_real = 0;
	z_img = 0;
	c_real = img->c_real;
	c_img = img->c_img;
	while (z_real * z_real + z_img * z_img < 4 && ++img->count_iter < ITER_NBR)
	{
		tmp = z_real * z_real * z_real - 3 * z_real * z_img * z_img + c_real;
		z_img = 3 * z_real * z_real * z_img - z_img * z_img * z_img + c_img;
		z_real = tmp;
	}
	img->zn = sqrt(z_img * z_img + z_real * z_real);
}
