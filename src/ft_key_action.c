/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:39:31 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/05/20 15:55:52 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_paral_move(int key, t_image *img)
{
	if (key == 123)
		img->dx += ((50 - W_SIZE / 2) * 4 / (img->zoom * W_SIZE)) / 6;
	else if (key == 124)
		img->dx += (-(50 - W_SIZE / 2) * 4 / (img->zoom * W_SIZE)) / 6;
	else if (key == 125)
		img->dy += (-(50 - W_SIZE / 2) * 4 / (img->zoom * W_SIZE)) / 6;
	else if (key == 126)
		img->dy += ((50 - W_SIZE / 2) * 4 / (img->zoom * W_SIZE)) / 6;
}

void		ft_scale_transform(int key, t_image *img)
{
	if (key == 69)
		img->zoom = img->zoom + img->zoom * 0.05;
	if (key == 78 && img->zoom > 0)
		img->zoom = img->zoom - img->zoom * 0.05;
}

void		ft_color_transform(int key, t_image *img)
{
	if (key == 8)
	{
		if (img->black_white == 0)
			img->black_white = 1;
		else
			img->black_white = 0;
	}
	if (key == 15)
		img->red += 1;
	if (key == 5)
		img->green += 1;
	if (key == 11)
		img->blue += 1;
}

void		ft_choose_fractol(int key, t_image *img)
{
	if (key == 91)
		img->fract_type = 8;
	else
		img->fract_type = key - 82;
	ft_null_params(img);
}

int			ft_key_action(int key, t_window *win)
{
	t_image		*img;

	img = win->img;
	if (key == 53)
	{
		ft_exit(win);
		return (0);
	}
	if (key == 69 || key == 78)
		ft_scale_transform(key, img);
	if (key == 123 || key == 124 || key == 125 || key <= 126)
		ft_paral_move(key, img);
	if (key == 8 || key == 15 || key == 5 || key == 11)
		ft_color_transform(key, img);
	if ((key >= 83 && key <= 89) || key == 91)
		ft_choose_fractol(key, img);
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	ft_clear_str(img->str, img->bpl * W_SIZE);
	ft_draw_fractol(img);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
	ft_put_description_str(win);
	return (0);
}
