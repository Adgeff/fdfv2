/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotzoomup_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 06:39:41 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 12:40:56 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_zoomup(t_env *fdf)
{
	fdf->zoom = fdf->zoom + ZOOM_STEP * fdf->zoom / 1000;
	ft_calc_real(fdf);
	ft_calc_rot(fdf);
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}

void		ft_rotxup(t_env *fdf)
{
	int		rot;

	rot = (ROT_STEP * 1000 / fdf->zoom) ? ROT_STEP * 1000 / fdf->zoom : 1;
	fdf->x_axis = ft_rotx(fdf->x_axis, rot);
	fdf->y_axis = ft_rotx(fdf->y_axis, rot);
	fdf->z_axis = ft_rotx(fdf->z_axis, rot);
	ft_calc_rot(fdf);
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}

void		ft_rotyup(t_env *fdf)
{
	int		rot;

	rot = (ROT_STEP * 1000 / fdf->zoom) ? ROT_STEP * 1000 / fdf->zoom : 1;
	fdf->x_axis = ft_roty(fdf->x_axis, rot);
	fdf->y_axis = ft_roty(fdf->y_axis, rot);
	fdf->z_axis = ft_roty(fdf->z_axis, rot);
	ft_calc_rot(fdf);
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}

void		ft_rotzup(t_env *fdf)
{
	int		rot;

	rot = (ROT_STEP * 1000 / fdf->zoom) ? ROT_STEP * 1000 / fdf->zoom : 1;
	fdf->x_axis = ft_rotz(fdf->x_axis, rot);
	fdf->y_axis = ft_rotz(fdf->y_axis, rot);
	fdf->z_axis = ft_rotz(fdf->z_axis, rot);
	ft_calc_rot(fdf);
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}
