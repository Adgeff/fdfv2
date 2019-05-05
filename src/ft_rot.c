/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 02:09:09 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 05:42:31 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	ft_rotx(t_coord coord, int rot)
{
	return ((t_coord){coord.x,
		(int)round((cos((double)rot / 1000.0 * PI) * coord.y) +
		(-sin((double)rot / 1000.0 * PI) * coord.z)),
		(int)round((sin((double)rot / 1000.0 * PI) * coord.y) +
		(cos((double)rot / 1000.0 * PI) * coord.z))});
}

t_coord	ft_roty(t_coord coord, int rot)
{
	return ((t_coord){(int)round((cos((double)rot / 1000.0 * PI) * coord.x) +
		(sin((double)rot / 1000.0 * PI) * coord.z)),
		coord.y,
		(int)round((-sin((double)rot / 1000.0 * PI) * coord.x) +
		(cos((double)rot / 1000.0 * PI) * coord.z))});
}

t_coord	ft_rotz(t_coord coord, int rot)
{
	return ((t_coord){(int)round((cos((double)rot / 1000.0 * PI) * coord.x) +
		(-sin((double)rot / 1000.0 * PI) * coord.y)),
		(int)round((sin((double)rot / 1000.0 * PI) * coord.x) +
		(cos((double)rot / 1000.0 * PI) * coord.y)),
		coord.z});
}
