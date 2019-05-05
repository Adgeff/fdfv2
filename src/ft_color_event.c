/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 05:54:33 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 05:54:44 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_colorpicker_map_event(int color, void *param)
{
	t_env	*fdf;

	fdf = param;
	fdf->map_color = color;
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
	return (0);
}

int			ft_colorpicker_back_event(int color, void *param)
{
	t_env	*fdf;

	fdf = param;
	fdf->back_color = color;
	ft_draw_img(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
	return (0);
}
