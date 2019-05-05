/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 05:48:56 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 10:14:46 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_shiftup(t_env *fdf)
{
	if (SHIFT_STEP * 1000 / fdf->zoom)
		fdf->y_shift = fdf->y_shift + SHIFT_STEP * 1000 / fdf->zoom;
	else
		fdf->y_shift = fdf->y_shift + 1;
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}

void		ft_shiftdown(t_env *fdf)
{
	if (SHIFT_STEP * 1000 / fdf->zoom)
		fdf->y_shift = fdf->y_shift - SHIFT_STEP * 1000 / fdf->zoom;
	else
		fdf->y_shift = fdf->y_shift - 1;
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}

void		ft_shiftleft(t_env *fdf)
{
	if (SHIFT_STEP * 1000 / fdf->zoom)
		fdf->x_shift = fdf->x_shift + SHIFT_STEP * 1000 / fdf->zoom;
	else
		fdf->x_shift = fdf->x_shift + 1;
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}

void		ft_shiftright(t_env *fdf)
{
	if (SHIFT_STEP * 1000 / fdf->zoom)
		fdf->x_shift = fdf->x_shift - SHIFT_STEP * 1000 / fdf->zoom;
	else
		fdf->x_shift = fdf->x_shift - 1;
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}
