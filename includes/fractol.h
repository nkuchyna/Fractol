/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:37:24 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/05/20 15:58:18 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define ITER_NBR 100
# define W_SIZE 1000
# define NUM_THREADS 4

# include <string.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include <pthread.h>

typedef struct	s_image
{
	void		*img_ptr;
	char		*str;
	int			bpp;
	int			bpl;
	int			end;
	int			fract_type;
	double		count_iter;
	double		zoom;
	double		dx;
	double		dy;
	double		red;
	double		green;
	double		blue;
	int			black_white;
	double		zn;
	int			id_thread;
	double		real_p;
	double		img_p;
	double		c_real;
	double		c_img;
	int			change_julia;
}				t_image;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*img;
}				t_window;

int				ft_define_fractol(char *argv, t_image *img);
void			ft_print_usage(void);
void			ft_exit(t_window *win);
int				ft_exit_x(void);
void			ft_null_params(t_image *img);
int				ft_key_action(int key, t_window *win);
int				ft_mouse_button_action(int button, int x, int y, t_window *win);
int				ft_mouse_moving(int x, int y, t_window *win);
int				ft_draw_fractol(t_image *img);
void			ft_mandelbrot(t_image *img);
void			ft_julia(t_image *img);
void			ft_burning_ship(t_image *img);
void			ft_flower(t_image *img);
void			ft_beetle(t_image *img);
void			ft_celtic(t_image *img);
void			ft_iricorn(t_image *img);
void			ft_heart(t_image *img);
void			ft_put_description_str(t_window *win);

#endif
