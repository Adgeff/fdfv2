/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:18:20 by geargenc          #+#    #+#             */
/*   Updated: 2018/02/20 13:22:47 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_colorpicker.h"
# include "mlx_keycode.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdio.h>

# define WIN_HEIGHT 800
# define WIN_WIDTH 1200
# define PADDING 50
# define H_SPACE 2
# define ZOOM_STEP 100
# define ROT_STEP 50
# define SHIFT_STEP 25

# define PI 3.1415926535

typedef struct	s_coord
{
	int			x;
	int			y;
	int			z;
}				t_coord;

typedef struct	s_img
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	int			x_size;
	int			y_size;
	int			x;
	int			y;
}				t_img;

typedef struct	s_cursor
{
	int			button;
	int			x;
	int			y;
}				t_cursor;

typedef struct	s_env
{
	char		*map_name;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*map_clrpick;
	void		*back_clrpick;
	t_img		img;
	t_coord		**data;
	t_coord		**real;
	t_coord		**rot;
	t_coord		**shift;
	t_cursor	cursor;
	t_coord		x_axis;
	t_coord		y_axis;
	t_coord		z_axis;
	int			space;
	int			zoom;
	int			x_size;
	int			y_size;
	int			x_shift;
	int			y_shift;
	int			map_color;
	int			back_color;
}				t_env;

typedef struct	s_keypress
{
	int			keycode;
	void		(*f)(t_env *);
}				t_keypress;

int				ft_parsefdf(int fd, t_env *fdf);
void			ft_img_lineput(t_coord a, t_coord b, t_env *fdf);
int				ft_img_pixelput(t_img *img, int x, int y, int color);
void			ft_img_clear(t_img *img, int color);
void			ft_openerror(char *prog, char *file);
void			ft_argerror(char *prog);
void			ft_config(t_env *fdf);
int				ft_config_real(t_env *fdf);
int				ft_config_rot(t_env *fdf);
int				ft_config_shift(t_env *fdf);
int				ft_config_mlx(t_env *fdf);
void			ft_calc_real(t_env *fdf);
void			ft_calc_rot(t_env *fdf);
void			ft_calc_shift(t_env *fdf);
void			ft_draw_img(t_env *fdf);
int				ft_colorpicker_map_event(int color, void *param);
int				ft_colorpicker_back_event(int color, void *param);
int				ft_buttonpress_event(int button, int x, int y, void *param);
int				ft_buttonrelease_event(int button, int x, int y, void *param);
int				ft_motionnotify_event(int x, int y, void *param);
int				ft_keypress_event(int keycode, void *param);
int				ft_destroynotify_event(void *param);
void			ft_zoomup(t_env *fdf);
void			ft_zoomdown(t_env *fdf);
void			ft_shiftup(t_env *fdf);
void			ft_shiftdown(t_env *fdf);
void			ft_shiftleft(t_env *fdf);
void			ft_shiftright(t_env *fdf);
void			ft_rotxup(t_env *fdf);
void			ft_rotxdown(t_env *fdf);
void			ft_rotyup(t_env *fdf);
void			ft_rotydown(t_env *fdf);
void			ft_rotzup(t_env *fdf);
void			ft_rotzdown(t_env *fdf);
void			ft_reset(t_env *fdf);
void			ft_exit(t_env *fdf);
t_coord			ft_rotx(t_coord coord, int rot);
t_coord			ft_roty(t_coord coord, int rot);
t_coord			ft_rotz(t_coord coord, int rot);

#endif
