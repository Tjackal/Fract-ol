/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 22:46:13 by tmarchen          #+#    #+#             */
/*   Updated: 2018/04/01 22:46:16 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	scale(t_fract_params *p, int x, int y, int in_out)
{
	if (in_out)
	{
		p->dx *= SCALE;
		p->dy *= SCALE;
		p->x0 += (x - (long double)x / WX * WX * SCALE) * p->stp_x;
		p->y0 += (y - (long double)y / WY * WY * SCALE) * p->stp_y;
	}
	else
	{
		p->dx *= 2.0 - SCALE;
		p->dy *= 2.0 - SCALE;
		p->x0 += (x - (long double)x / WX * WX * (2.0 - SCALE)) * p->stp_x;
		p->y0 += (y - (long double)y / WY * WY * (2.0 - SCALE)) * p->stp_y;
	}
	p->x1 = p->x0 + p->dx;
	p->y1 = p->y0 + p->dy;
}

void	move(t_fract_params *p, int dir)
{
	if (dir == 126)
	{
		p->y0 -= (float)(p->y1 - p->y0) * MOVE;
		p->y1 -= (float)(p->y1 - p->y0) * MOVE;
	}
	else if (dir == 124)
	{
		p->x0 += (float)(p->x1 - p->x0) * MOVE;
		p->x1 += (float)(p->x1 - p->x0) * MOVE;
	}
	else if (dir == 125)
	{
		p->y0 += (float)(p->y1 - p->y0) * MOVE;
		p->y1 += (float)(p->y1 - p->y0) * MOVE;
	}
	else if (dir == 123)
	{
		p->x0 -= (float)(p->x1 - p->x0) * MOVE;
		p->x1 -= (float)(p->x1 - p->x0) * MOVE;
	}
}

void	*mllc(unsigned int siz)
{
	void *p;

	if (!(p = malloc(siz)))
	{
		ft_putstr("allocation failed!\n");
		exit(1);
	}
	return (p);
}

int		quit(void *param)
{
	mlx_destroy_image((((t_all*)param)->mlx_d)->mlx,
	((((t_all*)param)->mlx_d)->img)->img);
	mlx_destroy_window((((t_all*)param)->mlx_d)->mlx,
	(((t_all*)param)->mlx_d)->window);
	free((((t_all*)param)->mlx_d)->img);
	free(((t_all*)param)->mlx_d);
	free(((t_all*)param)->fract_par);
	free(param);
	exit(1);
	return (0);
}
