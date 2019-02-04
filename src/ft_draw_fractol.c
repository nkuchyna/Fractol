/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:25:08 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/05/31 15:34:07 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_add_point_to_img_str(t_image *img, double x, double y, double zn)
{
	char		*str;
	int			i;
	double		index;
	double		phase;

	str = img->str;
	i = y * img->bpl + x * 4;
	index = img->count_iter + 1 - 2 * (log(2) / zn) / log(2);
	phase = 1;
	if (img->black_white == 1)
		phase = 0;
	str[i] = sin(5 * index + phase * img->blue + 2) * 80 + 128;
	str[++i] = sin(5 * index + phase * img->green + 2) * 80 + 128;
	str[++i] = sin(5 * index + phase * img->red + 2) * 80 + 128;
}

void	ft_calculate_fractol_point(t_image *img)
{
	if (img->fract_type == 1)
		ft_mandelbrot(img);
	else if (img->fract_type == 2)
		ft_julia(img);
	else if (img->fract_type == 3)
		ft_burning_ship(img);
	else if (img->fract_type == 4)
		ft_flower(img);
	else if (img->fract_type == 5)
		ft_beetle(img);
	else if (img->fract_type == 6)
		ft_celtic(img);
	else if (img->fract_type == 7)
		ft_iricorn(img);
	else if (img->fract_type == 8)
		ft_heart(img);
}

void	*ft_draw_fractol_part(void *new_image)
{
	int			y_range;
	double		x;
	double		y;
	t_image		*img;

	img = (t_image *)new_image;
	y_range = img->id_thread * W_SIZE / NUM_THREADS;
	y = y_range - W_SIZE / NUM_THREADS;
	while (y < y_range)
	{
		img->c_img = (y - W_SIZE / 2) * 4 / (img->zoom * W_SIZE) + img->dy;
		x = 0;
		while (x < W_SIZE)
		{
			img->count_iter = 0;
			img->c_real = (x - W_SIZE / 2) * 4 / (img->zoom * W_SIZE) + img->dx;
			ft_calculate_fractol_point(img);
			if (img->count_iter < ITER_NBR)
				ft_add_point_to_img_str(img, x, y, img->zn);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	ft_copy_img_content(t_image *img_array, t_image *img)
{
	int		k;

	k = -1;
	while (++k < NUM_THREADS)
	{
		img_array[k].img_ptr = img->img_ptr;
		img_array[k].str = img->str;
		img_array[k].bpp = img->bpp;
		img_array[k].bpl = img->bpl;
		img_array[k].end = img->end;
		img_array[k].fract_type = img->fract_type;
		img_array[k].count_iter = img->count_iter;
		img_array[k].zoom = img->zoom;
		img_array[k].dx = img->dx;
		img_array[k].dy = img->dy;
		img_array[k].red = img->red;
		img_array[k].green = img->green;
		img_array[k].blue = img->blue;
		img_array[k].black_white = img->black_white;
		img_array[k].id_thread = k + 1;
		img_array[k].zn = 0;
		img_array[k].real_p = img->real_p;
		img_array[k].img_p = img->img_p;
		img_array[k].change_julia = img->change_julia;
	}
}

int		ft_draw_fractol(t_image *img)
{
	t_image		*img_array;
	pthread_t	thread[NUM_THREADS];
	int			k;

	k = 0;
	if (!(img_array = (t_image*)malloc(sizeof(t_image) * NUM_THREADS)))
		return (1);
	ft_copy_img_content(img_array, img);
	while (k < NUM_THREADS)
	{
		pthread_create(&thread[k], NULL, &ft_draw_fractol_part, &img_array[k]);
		k++;
	}
	k = 0;
	while (k < NUM_THREADS)
	{
		pthread_join(thread[k], NULL);
		k++;
	}
	free(img_array);
	return (0);
}
