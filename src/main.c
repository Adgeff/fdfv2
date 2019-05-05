/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:44:06 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 13:23:07 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_img(t_env *fdf)
{
	int		i;
	int		j;

	ft_img_clear(&(fdf->img), fdf->back_color);
	j = 0;
	while (j < fdf->y_size)
	{
		i = 0;
		while (i < fdf->x_size)
		{
			if (i < fdf->x_size - 1)
				ft_img_lineput(fdf->shift[j][i], fdf->shift[j][i + 1], fdf);
			if (j < fdf->y_size - 1)
				ft_img_lineput(fdf->shift[j][i], fdf->shift[j + 1][i], fdf);
			i++;
		}
		j++;
	}
}

int			fdf(int fd, char *name)
{
	t_env	fdf;

	fdf.map_name = ft_strrchr(name, '/');
	fdf.map_name = fdf.map_name ? fdf.map_name + 1 : name;
	if (ft_parsefdf(fd, &fdf))
		return (1);
	ft_config(&fdf);
	if (ft_config_real(&fdf) ||
		ft_config_rot(&fdf) ||
		ft_config_shift(&fdf) ||
		ft_config_mlx(&fdf))
		return (1);
	ft_draw_img(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.ptr, 0, 0);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_openerror(argv[0], argv[1]);
		else if (fdf(fd, argv[1]))
			ft_putendl_fd("Error\n", 2);
	}
	else
		ft_argerror(argv[0]);
	return (0);
}
