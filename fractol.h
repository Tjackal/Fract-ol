/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 01:51:32 by tmarchen          #+#    #+#             */
/*   Updated: 2018/03/05 01:52:12 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <pthread.h>

# define WX 1200
# define WY 800

# define SCALE 0.93
# define MOVE 0.03

# define E 0.000001

typedef struct		s_img
{
	int		*data;
	void	*img;
	int		bpp;
	int		sz;
	int		endian;
}					t_img;

typedef struct		s_mlx_d
{
	void	*mlx;
	void	*window;
	t_img	*img;
}					t_mlx_d;

typedef struct		s_fract_params
{
	long double x0;
	long double x1;
	long double y0;
	long double y1;
	long double stp_x;
	long double stp_y;
	long double dx;
	long double dy;
	long double m_x;
	long double m_y;
	int			(*check)(long double, long double, struct s_fract_params*);
	int			maxi;
}					t_fract_params;

typedef struct		s_all
{
	t_mlx_d			*mlx_d;
	t_fract_params	*fract_par;
}					t_all;

typedef struct		s_thread_data
{
	t_img			*img;
	t_fract_params	*p;
	int				part;
}					t_thread_data;

typedef struct		s_calc_params
{
	int			w;
	int			w_reset;
	int			h;
	long double stop_x;
	long double stop_y;
	long double x;
	long double x_reset;
	long double y;
}					t_calc_params;

int					buffalo_check(long double x, long double y,
					t_fract_params *p);

int					tricorn_check(long double x, long double y,
					t_fract_params *p);

int					celtic_check(long double x, long double y,
					t_fract_params *p);

int					zhopa_check(long double x, long double y,
					t_fract_params *p);

int					julia_check(long double xt, long double yt,
					t_fract_params *p);

int					pool_check(long double x, long double y,
					t_fract_params *p);

int					julia2_check(long double xt, long double yt,
					t_fract_params *p);

int					burnin_check(long double x, long double y,
					t_fract_params *p);

void				scale(t_fract_params *p, int x, int y, int in_out);

void				move(t_fract_params *p, int dir);

void				*mllc(unsigned int siz);

int					quit(void *param);

void				set_params_for_part(int part, t_fract_params *p,
					t_calc_params *c);

void				zhopa(t_img *img, t_fract_params *p);

int					mouse(int button, int x, int y, void *par);

int					key(int button, void *par);

int					mouse_move(int x, int y, void *par);

int					get_par(char *argv);

#endif
