/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 06:15:27 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/13 13:14:43 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	***ft_getlines(int fd, int nbr)
{
	char	*line;
	char	***tab;
	int		ret;

	if ((ret = get_next_line(fd, &line)) < 0)
		return (NULL);
	else if (ret > 0)
	{
		if (!(tab = ft_getlines(fd, nbr + 1)) ||
			!(tab[nbr] = ft_strsplitwhitespaces(line)))
			return (NULL);
		free(line);
	}
	else
	{
		if (!(tab = (char ***)malloc((nbr + 1) * sizeof(char **))))
			return (NULL);
		tab[nbr] = NULL;
	}
	return (tab);
}

static int	ft_checkmap(t_env *fdf, char ***tab)
{
	int		i;
	int		j;

	fdf->x_size = -1;
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
			i++;
		if (fdf->x_size < 0)
			fdf->x_size = i;
		else if (i != fdf->x_size)
			return (1);
		j++;
	}
	fdf->y_size = j;
	return (fdf->x_size < 2 || fdf->y_size < 2);
}

static int	ft_getdata(t_env *fdf, char ***tab)
{
	int		i;
	int		j;

	if (!(fdf->data = (t_coord **)malloc(fdf->y_size * sizeof(t_coord *))))
		return (1);
	j = 0;
	while (j < fdf->y_size)
	{
		if (!(fdf->data[j] = (t_coord *)malloc(fdf->x_size * sizeof(t_coord))))
			return (1);
		i = 0;
		while (i < fdf->x_size)
		{
			fdf->data[j][i].x = i;
			fdf->data[j][i].y = ft_atoi(tab[j][i]);
			fdf->data[j][i].z = j;
			free(tab[j][i]);
			i++;
		}
		free(tab[j]);
		j++;
	}
	free(tab);
	return (0);
}

int			ft_parsefdf(int fd, t_env *fdf)
{
	char	***tab;

	if (!(tab = ft_getlines(fd, 0)) ||
		ft_checkmap(fdf, tab) ||
		ft_getdata(fdf, tab) ||
		close(fd) < 0)
		return (1);
	return (0);
}
