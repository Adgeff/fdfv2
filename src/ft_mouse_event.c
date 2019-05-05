/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 05:46:07 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 13:31:12 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_buttonpress_event(int button, int x, int y, void *param)
{
	t_env	*fdf;

	fdf = param;
	if ((button == 1 || button == 2) && x >= fdf->img.x && x < fdf->img.x +
		fdf->img.x_size && y >= fdf->img.y && y < fdf->img.y + fdf->img.y_size)
		fdf->cursor = (t_cursor){button, x, y};
	else if (button == 4)
		ft_zoomup(fdf);
	else if (button == 5)
		ft_zoomdown(fdf);
	return (0);
}

int			ft_buttonrelease_event(int button, int x, int y, void *param)
{
	t_env	*fdf;

	fdf = param;
	if (button == fdf->cursor.button)
		fdf->cursor = (t_cursor){0, x, y};
	return (0);
}

static void	ft_motionbutton1_event(int x, int y, t_env *fdf)
{
	if ((x - fdf->cursor.x) * 1000 / fdf->zoom)
	{
		fdf->x_shift = fdf->x_shift + (x - fdf->cursor.x) * 1000 / fdf->zoom;
		fdf->cursor.x = x;
	}
	if ((y - fdf->cursor.y) * 1000 / fdf->zoom)
	{
		fdf->y_shift = fdf->y_shift + (y - fdf->cursor.y) * 1000 / fdf->zoom;
		fdf->cursor.y = y;
	}
}

static void	ft_motionbutton2_event(int x, int y, t_env *fdf)
{
	if ((fdf->cursor.x - x) * 1000 / fdf->zoom)
	{
		fdf->x_axis = ft_roty(fdf->x_axis,
			(fdf->cursor.x - x) * 1000 / fdf->zoom);
		fdf->y_axis = ft_roty(fdf->y_axis,
			(fdf->cursor.x - x) * 1000 / fdf->zoom);
		fdf->z_axis = ft_roty(fdf->z_axis,
			(fdf->cursor.x - x) * 1000 / fdf->zoom);
		fdf->cursor.x = x;
	}
	if ((y - fdf->cursor.y) * 1000 / fdf->zoom)
	{
		fdf->x_axis = ft_rotx(fdf->x_axis,
			(y - fdf->cursor.y) * 1000 / fdf->zoom);
		fdf->y_axis = ft_rotx(fdf->y_axis,
			(y - fdf->cursor.y) * 1000 / fdf->zoom);
		fdf->z_axis = ft_rotx(fdf->z_axis,
			(y - fdf->cursor.y) * 1000 / fdf->zoom);
		fdf->cursor.y = y;
	}
}

int			ft_motionnotify_event(int x, int y, void *param)
{
	t_env	*fdf;

	fdf = param;
	if (fdf->cursor.button == 1)
		ft_motionbutton1_event(x, y, fdf);
	else if (fdf->cursor.button == 2)
	{
		ft_motionbutton2_event(x, y, fdf);
		ft_calc_rot(fdf);
	}
	else
		return (0);
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
	return (0);
}
