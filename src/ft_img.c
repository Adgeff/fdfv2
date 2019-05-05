/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 05:30:22 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/13 15:00:32 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_img_pixelput(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < img->x_size && y >= 0 && y < img->y_size)
		*((int *)img->data + y * img->x_size + x) = color;
	else
		return (1);
	return (0);
}

void		ft_img_clear(t_img *img, int color)
{
	int		i;
	int		j;

	j = 0;
	while (j < img->y_size)
	{
		i = 0;
		while (i < img->x_size)
		{
			ft_img_pixelput(img, i, j, color);
			i++;
		}
		j++;
	}
}
