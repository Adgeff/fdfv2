/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotzoomdown_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 05:53:17 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 12:42:30 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_zoomdown(t_env *fdf)
{
	if (fdf->zoom > ZOOM_STEP)
	{
		fdf->zoom = fdf->zoom - ZOOM_STEP * fdf->zoom / 1000;
		ft_calc_real(fdf);
		ft_calc_rot(fdf);
		ft_calc_shift(fdf);
		ft_draw_img(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
	}
}

void		ft_rotxdown(t_env *fdf)
{
	int		rot;

	rot = (-ROT_STEP * 1000 / fdf->zoom) ? -ROT_STEP * 1000 / fdf->zoom : -1;
	fdf->x_axis = ft_rotx(fdf->x_axis, rot);
	fdf->y_axis = ft_rotx(fdf->y_axis, rot);
	fdf->z_axis = ft_rotx(fdf->z_axis, rot);
	ft_calc_rot(fdf);
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}

void		ft_rotydown(t_env *fdf)
{
	int		rot;

	rot = (-ROT_STEP * 1000 / fdf->zoom) ? -ROT_STEP * 1000 / fdf->zoom : -1;
	fdf->x_axis = ft_roty(fdf->x_axis, rot);
	fdf->y_axis = ft_roty(fdf->y_axis, rot);
	fdf->z_axis = ft_roty(fdf->z_axis, rot);
	ft_calc_rot(fdf);
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}

void		ft_rotzdown(t_env *fdf)
{
	int		rot;

	rot = (-ROT_STEP * 1000 / fdf->zoom) ? -ROT_STEP * 1000 / fdf->zoom : -1;
	fdf->x_axis = ft_rotz(fdf->x_axis, rot);
	fdf->y_axis = ft_rotz(fdf->y_axis, rot);
	fdf->z_axis = ft_rotz(fdf->z_axis, rot);
	ft_calc_rot(fdf);
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}
