/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 05:56:45 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 05:56:55 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_config_img(t_env *fdf)
{
	if (!(fdf->img.ptr = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (1);
	fdf->img.data = mlx_get_data_addr(fdf->img.ptr, &(fdf->img.bpp),
		&(fdf->img.sl), &(fdf->img.endian));
	fdf->img.x_size = WIN_WIDTH;
	fdf->img.y_size = WIN_HEIGHT;
	fdf->img.x = 0;
	fdf->img.y = 0;
	return (0);
}

int			ft_config_mlx(t_env *fdf)
{
	if (!(fdf->mlx_ptr = mlx_init()) ||
		!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
		fdf->map_name)) ||
		ft_config_img(fdf) ||
		!(fdf->map_clrpick = ft_colorpicker(fdf->mlx_ptr,
		&ft_colorpicker_map_event, fdf, "map color")) ||
		!(fdf->back_clrpick = ft_colorpicker(fdf->mlx_ptr,
		&ft_colorpicker_back_event, fdf, "background color")))
		return (1);
	mlx_hook(fdf->win_ptr, BUTTONPRESS, BUTTONPRESSMASK,
		&ft_buttonpress_event, fdf);
	mlx_hook(fdf->win_ptr, BUTTONRELEASE, BUTTONRELEASEMASK,
		&ft_buttonrelease_event, fdf);
	mlx_hook(fdf->win_ptr, MOTIONNOTIFY, POINTERMOTIONMASK,
		&ft_motionnotify_event, fdf);
	mlx_hook(fdf->win_ptr, KEYPRESS, KEYPRESSMASK,
		&ft_keypress_event, fdf);
	mlx_hook(fdf->win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK,
		&ft_destroynotify_event, fdf);
	mlx_do_key_autorepeaton(fdf->mlx_ptr);
	return (0);
}
