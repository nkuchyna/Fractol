/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_fractol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:40:10 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/05/20 15:37:46 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_usage(void)
{
	ft_putendl("usage: fractol [fractol_type]");
	ft_putendl("You can choose one of the folloving fractol types:\
				\n- mandelbrot;\n- julia;\n- burning_ship;\n- flower;\
				\n- beetle;\n- celtic;\n- iricorn.");
}

int		ft_define_fractol(char *argv, t_image *img)
{
	if (ft_strcmp(argv, "mandelbrot") == 0)
		img->fract_type = 1;
	else if (ft_strcmp(argv, "julia") == 0)
		img->fract_type = 2;
	else if (ft_strcmp(argv, "burning_ship") == 0)
		img->fract_type = 3;
	else if (ft_strcmp(argv, "flower") == 0)
		img->fract_type = 4;
	else if (ft_strcmp(argv, "beetle") == 0)
		img->fract_type = 5;
	else if (ft_strcmp(argv, "celtic") == 0)
		img->fract_type = 6;
	else if (ft_strcmp(argv, "iricorn") == 0)
		img->fract_type = 7;
	else if (ft_strcmp(argv, "heart") == 0)
		img->fract_type = 8;
	else
	{
		ft_print_usage();
		return (1);
	}
	return (0);
}
