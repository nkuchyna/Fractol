/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_math2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:06:18 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/05/20 15:46:04 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_iricorn(t_image *img)
{
	double		z_real;
	double		z_img;
	double		tmp;

	z_real = 0;
	z_img = 0;
	while (z_real * z_real + z_img * z_img < 4 && ++img->count_iter < ITER_NBR)
	{
		tmp = z_real * z_real - z_img * z_img + img->c_real;
		z_img = -2 * z_real * z_img + img->c_img;
		z_real = tmp;
	}
	img->zn = sqrt(z_img * z_img + z_real * z_real);
}

void	ft_celtic(t_image *img)
{
	double		z_real;
	double		z_img;
	double		tmp;

	z_real = 0;
	z_img = 0;
	while (z_real * z_real + z_img * z_img < 4 && ++img->count_iter < ITER_NBR)
	{
		tmp = fabs(z_real * z_real - z_img * z_img) + img->c_real;
		z_img = -2 * z_real * z_img + img->c_img;
		z_real = tmp;
	}
	img->zn = sqrt(z_img * z_img + z_real * z_real);
}

void	ft_heart(t_image *img)
{
	double		z_real;
	double		z_img;
	double		tmp;

	z_real = 0;
	z_img = 0;
	while (z_real * z_real + z_img * z_img < 4 && ++img->count_iter < ITER_NBR)
	{
		tmp = z_real * z_real - z_img * z_img + img->c_real;
		z_img = 2 * fabs(z_real) * z_img + img->c_img;
		z_real = tmp;
	}
	img->zn = sqrt(z_img * z_img + z_real * z_real);
}
