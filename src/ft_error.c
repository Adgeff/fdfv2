/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 05:29:37 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/13 15:01:17 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_openerror(char *prog, char *file)
{
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	ft_argerror(char *prog)
{
	ft_putstr_fd("Usage : ", 2);
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(" <file>\n", 2);
}
