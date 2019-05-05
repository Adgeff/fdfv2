/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_lineput.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:52:13 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 13:35:17 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_check(t_coord a, t_coord b, t_env *fdf)
{
	return (!((a.x < fdf->img.x && b.x < fdf->img.x) ||
		(a.x >= fdf->img.x_size + fdf->img.x &&
		b.x >= fdf->img.x_size + fdf->img.x) ||
		(a.y < fdf->img.y && b.y < fdf->img.y) ||
		(a.y >= fdf->img.y_size + fdf->img.y
		&& b.y >= fdf->img.y_size + fdf->img.y)));
}

static void	ft_img_lineput_vert(t_coord a, t_coord b, t_env *fdf)
{
	int		i;

	if (a.y > b.y)
		ft_img_lineput_vert(b, a, fdf);
	else
	{
		i = a.y;
		while (i <= b.y)
		{
			ft_img_pixelput(&(fdf->img), a.x, i, fdf->map_color);
			i++;
		}
	}
}

static void	ft_img_lineput_y(t_coord a, t_coord b, t_env *fdf)
{
	int		i;
	int		slope;
	int		ord;

	if (a.y > b.y)
		ft_img_lineput_y(b, a, fdf);
	else
	{
		slope = (b.y - a.y) * 1000 / (b.x - a.x);
		ord = a.y - slope * a.x / 1000;
		i = a.y;
		while (i <= b.y)
		{
			ft_img_pixelput(&(fdf->img), (i - ord) * 1000 / slope, i,
				fdf->map_color);
			i++;
		}
	}
}

static void	ft_img_lineput_x(t_coord a, t_coord b, t_env *fdf)
{
	int		i;
	int		slope;
	int		ord;

	slope = (b.y - a.y) * 1000 / (b.x - a.x);
	ord = a.y - slope * a.x / 1000;
	i = a.x;
	while (i <= b.x)
	{
		ft_img_pixelput(&(fdf->img), i, slope * i / 1000 + ord,
			fdf->map_color);
		i++;
	}
}

void		ft_img_lineput(t_coord a, t_coord b, t_env *fdf)
{
	if (ft_check(a, b, fdf))
	{
		if (a.x > b.x)
			ft_img_lineput(b, a, fdf);
		else if (a.x == b.x)
			ft_img_lineput_vert(a, b, fdf);
		else if ((b.y > a.y) ? b.y - a.y > b.x - a.x : a.y - b.y > b.x - a.x)
			ft_img_lineput_y(a, b, fdf);
		else
			ft_img_lineput_x(a, b, fdf);
	}
}
