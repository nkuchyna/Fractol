/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:47:23 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/05/20 15:54:03 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_put_description_str(t_window *win)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;

	str1 = "Choose fractal: 1 - 8";
	str2 = "Change color: R, G, B";
	str3 = "C - (black-white mode)";
	str4 = "Move: with errors";
	str5 = "Zoom: +/- or 'mouse'";
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 10, 16777215, str1);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 35, 16777215, str2);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 60, 16777215, str3);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 85, 16777215, str4);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 110, 16777215, str5);
}

void		ft_exit(t_window *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->img_ptr);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(1);
}

int			ft_exit_x(void)
{
	exit(1);
	return (0);
}

void		ft_null_params(t_image *img)
{
	img->count_iter = 0;
	img->zoom = 1;
	img->dx = 0;
	img->dy = 0;
	img->real_p = 0.7;
	img->img_p = 0.27015;
	img->change_julia = 0;
}
