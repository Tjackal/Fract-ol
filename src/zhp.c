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

int		clr(int res, int maxi)
{
	int		clr;
	double	t;

	if (res > 0)
	{
		t = (double)res / maxi;
		clr = 0;
		clr += ((int)(9 * (1 - t) * t * t * t * 255) << 16);
		clr += ((int)(4.5 * (1 - t) * (1 - t) * t * t * 255) << 8);
		clr += (int)(1.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		return (clr);
	}
	return (0);
}

void	squared_zhopa(t_img *img, t_fract_params *p, int part)
{
	t_calc_params *c;

	c = (t_calc_params*)mllc(sizeof(t_calc_params));
	c->stop_y = 0.0;
	c->x = 0.0;
	c->x_reset = 0.0;
	c->y = 0.0;
	set_params_for_part(part, p, c);
	while (c->y < c->stop_y && c->h < WY)
	{
		c->w = c->w_reset;
		c->x = c->x_reset;
		while (c->x < c->stop_x && c->w < WX)
		{
			img->data[c->h * WX + c->w] = clr(p->check(c->x, c->y, p), p->maxi);
			c->x += p->stp_x;
			(c->w)++;
		}
		c->y += p->stp_y;
		(c->h)++;
	}
	free(c);
}

void	*preliminaries(void *dd)
{
	t_thread_data *d;

	d = (t_thread_data*)dd;
	squared_zhopa(d->img, d->p, d->part);
	return (NULL);
}

void	zhopa(t_img *img, t_fract_params *p)
{
	int				i;
	pthread_t		t[4];
	t_thread_data	th_d[4];

	p->stp_x = (float)(p->x1 - p->x0) / WX;
	p->stp_y = (float)(p->y1 - p->y0) / WY;
	p->dx = (float)(p->x1 - p->x0);
	p->dy = (float)(p->y1 - p->y0);
	i = -1;
	while (++i < 4)
	{
		th_d[i].img = img;
		th_d[i].p = p;
		th_d[i].part = i + 1;
		pthread_create(&(t[i]), NULL, preliminaries, &(th_d[i]));
	}
	i = -1;
	while (++i < 4)
		pthread_join(t[i], NULL);
}
