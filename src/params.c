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

void	set_params_for_part_(int part, t_fract_params *p, t_calc_params *c)
{
	if (part == 3)
	{
		c->h = WY / 2;
		c->w_reset = 0;
		c->x_reset = p->x0;
		c->y = p->y1 - p->dy / 2;
		c->stop_x = p->x1 - p->dx / 2;
		c->stop_y = p->y1;
	}
	else if (part == 4)
	{
		c->h = WY / 2;
		c->w_reset = WX / 2;
		c->x_reset = p->x1 - p->dx / 2;
		c->y = p->y1 - p->dy / 2;
		c->stop_x = p->x1;
		c->stop_y = p->y1;
	}
}

void	set_params_for_part(int part, t_fract_params *p, t_calc_params *c)
{
	if (part == 1)
	{
		c->h = 0;
		c->w_reset = 0;
		c->x_reset = p->x0;
		c->y = p->y0;
		c->stop_x = p->x1 - p->dx / 2;
		c->stop_y = p->y1 - p->dy / 2;
	}
	else if (part == 2)
	{
		c->h = 0;
		c->w_reset = WX / 2;
		c->x_reset = p->x1 - p->dx / 2;
		c->y = p->y0;
		c->stop_x = p->x1;
		c->stop_y = p->y1 - p->dy / 2;
	}
	else
		set_params_for_part_(part, p, c);
}
