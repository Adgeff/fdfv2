/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 05:29:01 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 05:17:03 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_calc_real(t_env *fdf)
{
	int		i;
	int		j;

	j = 0;
	while (j < fdf->y_size)
	{
		i = 0;
		while (i < fdf->x_size)
		{
			fdf->real[j][i].x = (fdf->data[j][i].x * fdf->space -
				(fdf->x_size - 1) * fdf->space / 2) * fdf->zoom / 1000;
			fdf->real[j][i].y = fdf->data[j][i].y * H_SPACE * fdf->zoom / 1000;
			fdf->real[j][i].z = (fdf->data[j][i].z * fdf->space -
				(fdf->y_size - 1) * fdf->space / 2) * fdf->zoom / 1000;
			i++;
		}
		j++;
	}
}

static void	ft_calc_rot_coord(t_coord *from, t_coord *to, t_env *fdf)
{
	to->x = (from->x * fdf->x_axis.x + from->y * fdf->y_axis.x + from->z
		* fdf->z_axis.x) / 1000;
	to->y = (from->x * fdf->x_axis.y + from->y * fdf->y_axis.y + from->z
		* fdf->z_axis.y) / 1000;
	to->z = (from->x * fdf->x_axis.z + from->y * fdf->y_axis.z + from->z
		* fdf->z_axis.z) / 1000;
}

void		ft_calc_rot(t_env *fdf)
{
	int		i;
	int		j;

	j = 0;
	while (j < fdf->y_size)
	{
		i = 0;
		while (i < fdf->x_size)
		{
			ft_calc_rot_coord(&(fdf->real[j][i]), &(fdf->rot[j][i]), fdf);
			i++;
		}
		j++;
	}
}

void		ft_calc_shift(t_env *fdf)
{
	int		i;
	int		j;

	j = 0;
	while (j < fdf->y_size)
	{
		i = 0;
		while (i < fdf->x_size)
		{
			fdf->shift[j][i].x = fdf->rot[j][i].x +
				fdf->x_shift * fdf->zoom / 1000 + (WIN_WIDTH / 2);
			fdf->shift[j][i].y = fdf->rot[j][i].y +
				fdf->y_shift * fdf->zoom / 1000 + (WIN_HEIGHT / 2);
			i++;
		}
		j++;
	}
}
