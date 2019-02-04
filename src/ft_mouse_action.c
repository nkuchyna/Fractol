/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:01:13 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/05/20 19:27:24 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_button_action(int button, int x, int y, t_window *win)
{
	t_image		*img;

	img = win->img;
	if (button == 1)
	{
		if (img->change_julia == 0)
			img->change_julia = 1;
		else
			img->change_julia = 0;
	}
	if (button == 4 || button == 5)
	{
		if (button == 4 && img->zoom > 0)
			img->zoom = img->zoom + img->zoom * 0.05;
		if (button == 5)
			img->zoom = img->zoom - img->zoom * 0.05;
	}
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	ft_clear_str(img->str, img->bpl * W_SIZE);
	ft_draw_fractol(img);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
	ft_put_description_str(win);
	return (0);
}

int		ft_mouse_moving(int x, int y, t_window *win)
{
	t_image		*img;

	img = win->img;
	if (img->fract_type == 2 && img->change_julia == 1)
	{
		img->real_p = (x - (W_SIZE + img->dx) / 2) * 4 / (img->zoom * W_SIZE);
		img->img_p = (y - (W_SIZE + img->dy) / 2) * 4 / (img->zoom * W_SIZE);
	}
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	ft_clear_str(img->str, img->bpl * W_SIZE);
	ft_draw_fractol(img);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
	ft_put_description_str(win);
	return (0);
}
