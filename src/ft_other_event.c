/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 05:55:11 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 13:22:12 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void					ft_reset(t_env *fdf)
{
	ft_config(fdf);
	ft_calc_real(fdf);
	ft_calc_rot(fdf);
	ft_calc_shift(fdf);
	ft_draw_img(fdf);
	ft_reset_colorpicker(fdf->map_clrpick);
	ft_reset_colorpicker(fdf->back_clrpick);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
}

void					ft_exit(t_env *fdf)
{
	int					i;

	ft_close_colorpicker(fdf->map_clrpick);
	ft_close_colorpicker(fdf->back_clrpick);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	i = 0;
	while (i < fdf->y_size)
	{
		free(fdf->data[i]);
		free(fdf->real[i]);
		free(fdf->rot[i]);
		free(fdf->shift[i]);
		i++;
	}
	free(fdf->data);
	free(fdf->real);
	free(fdf->rot);
	free(fdf->shift);
	exit(EXIT_SUCCESS);
}

int						ft_keypress_event(int keycode, void *param)
{
	t_env				*fdf;
	int					i;
	static t_keypress	keypresstab[] =
	{	{PL_KEY, &ft_zoomup}, {MN_KEY, &ft_zoomdown}, {UP_KEY, &ft_shiftup},
		{DOWN_KEY, &ft_shiftdown}, {LEFT_KEY, &ft_shiftleft},
		{RIGHT_KEY, &ft_shiftright}, {W_KEY, &ft_rotxup}, {S_KEY, &ft_rotxdown},
		{D_KEY, &ft_rotyup}, {A_KEY, &ft_rotydown}, {Q_KEY, &ft_rotzup},
		{E_KEY, &ft_rotzdown}, {R_KEY, &ft_reset}, {ESC_KEY, &ft_exit},
		{0, NULL}
	};

	fdf = param;
	i = 0;
	while (keypresstab[i].f && keypresstab[i].keycode != keycode)
		i++;
	if (keypresstab[i].f)
		keypresstab[i].f(fdf);
	return (0);
}

int						ft_destroynotify_event(void *param)
{
	ft_exit(param);
	return (0);
}
