/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:44:47 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/05/20 19:27:21 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_window	*ft_create_win(void)
{
	void		*mlx_ptr;
	t_window	*win;

	if (!(mlx_ptr = mlx_init()))
		return (NULL);
	if (!(win = (t_window*)malloc(sizeof(t_window) * 1)))
		return (NULL);
	win->mlx_ptr = mlx_ptr;
	if (!(win->win_ptr = mlx_new_window(win->mlx_ptr, W_SIZE,
						W_SIZE, "Fractol")))
		return (NULL);
	return (win);
}

static t_image	*ft_create_img(t_window *win)
{
	t_image		*img;

	if (!(img = (t_image*)malloc(sizeof(t_image) * 1)))
		return (NULL);
	if (!(img->img_ptr = mlx_new_image(win->mlx_ptr, W_SIZE, W_SIZE)))
		return (NULL);
	img->fract_type = 1;
	img->count_iter = 0;
	img->zoom = 1;
	img->dx = 0;
	img->dy = 0;
	img->red = 3;
	img->green = 2;
	img->blue = 0;
	img->black_white = 0;
	img->real_p = 0.7;
	img->img_p = 0.27015;
	img->change_julia = 0;
	if (!(img->str = mlx_get_data_addr(img->img_ptr, &img->bpp,
						&img->bpl, &img->end)))
		return (NULL);
	win->img = img;
	return (img);
}

void			ft_put_fract_image(t_window *win, t_image *img)
{
	ft_draw_fractol(img);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
	ft_put_description_str(win);
}

int				main(int argc, char **argv)
{
	t_window	*win;
	t_image		*img;

	if (argc != 2)
	{
		ft_print_usage();
		return (1);
	}
	if (!(win = ft_create_win()))
		return (1);
	if (!(img = ft_create_img(win)))
		return (1);
	if (ft_define_fractol(argv[1], img) == 1)
	{
		ft_exit(win);
		return (1);
	}
	ft_put_fract_image(win, img);
	mlx_hook(win->win_ptr, 2, 5, &ft_key_action, win);
	mlx_mouse_hook(win->win_ptr, &ft_mouse_button_action, win);
	mlx_hook(win->win_ptr, 6, 0, &ft_mouse_moving, win);
	mlx_hook(win->win_ptr, 17, 1L << 17, ft_exit_x, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
