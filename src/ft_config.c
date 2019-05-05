/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 05:25:54 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 05:56:39 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_config(t_env *fdf)
{
	if ((fdf->space = ((WIN_HEIGHT < WIN_WIDTH ? WIN_HEIGHT : WIN_WIDTH)
		- PADDING * 2) / (fdf->y_size > fdf->x_size ? fdf->y_size
		: fdf->x_size)) < 1)
		fdf->space = 1;
	fdf->zoom = 1000;
	fdf->x_axis = (t_coord){707, 500, -500};
	fdf->y_axis = (t_coord){0, -707, -707};
	fdf->z_axis = (t_coord){-707, 500, -500};
	fdf->x_shift = 0;
	fdf->y_shift = 0;
	fdf->map_color = 0xFFFFFF;
	fdf->back_color = 0x0;
}

int			ft_config_real(t_env *fdf)
{
	int		i;

	if (!(fdf->real = (t_coord **)malloc(fdf->y_size * sizeof(t_coord *))))
		return (1);
	i = 0;
	while (i < fdf->y_size)
	{
		if (!(fdf->real[i] = (t_coord *)malloc(fdf->x_size * sizeof(t_coord))))
			return (1);
		i++;
	}
	ft_calc_real(fdf);
	return (0);
}

int			ft_config_rot(t_env *fdf)
{
	int		i;

	if (!(fdf->rot = (t_coord **)malloc(fdf->y_size * sizeof(t_coord *))))
		return (1);
	i = 0;
	while (i < fdf->y_size)
	{
		if (!(fdf->rot[i] = (t_coord *)malloc(fdf->x_size * sizeof(t_coord))))
			return (1);
		i++;
	}
	ft_calc_rot(fdf);
	return (0);
}

int			ft_config_shift(t_env *fdf)
{
	int		i;

	if (!(fdf->shift = (t_coord **)malloc(fdf->y_size * sizeof(t_coord *))))
		return (1);
	i = 0;
	while (i < fdf->y_size)
	{
		if (!(fdf->shift[i] = (t_coord *)malloc(fdf->x_size * sizeof(t_coord))))
			return (1);
		i++;
	}
	ft_calc_shift(fdf);
	return (0);
}
