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

void	roots_init(long double r[3][2])
{
	r[0][0] = 1.0;
	r[0][1] = 0.0;
	r[1][0] = -0.5;
	r[1][1] = -0.86603;
	r[2][0] = -0.5;
	r[2][1] = 0.86603;
}

int		pool_check(long double x, long double y, t_fract_params *p)
{
	int			i;
	int			maxi;
	long double xtt;
	long double xt;
	long double r[3][2];

	roots_init(r);
	i = 0;
	maxi = p->maxi;
	while (i < maxi)
	{
		if (((r[0][0] - x) * (r[0][0] - x) + (r[0][1] - y) * (r[0][1] - y) < E)
		|| ((r[1][0] - x) * (r[1][0] - x) + (r[1][1] - y) * (r[1][1] - y) < E)
		|| ((r[2][0] - x) * (r[2][0] - x) + (r[2][1] - y) * (r[2][1] - y) < E))
			return (i);
		xt = x;
		xtt = x * x + y * y;
		xtt *= xtt;
		x = (2 * x + (x * x - y * y) / xtt) / 3;
		y = (y - xt * y / xtt) * 2 / 3;
		i++;
	}
	return (-1);
}

int		julia2_check(long double xt, long double yt, t_fract_params *p)
{
	int			i;
	int			maxi;
	long double m_x;
	long double m_y;
	long double xtt;

	i = 0;
	maxi = p->maxi;
	m_x = p->m_x;
	m_y = p->m_y;
	while (i < maxi)
	{
		xtt = xt;
		xt = fabsl(xt * xt - yt * yt) + m_x;
		yt = 2 * xtt * yt + m_y;
		if (xt * xt + yt * yt > 4)
			return (i);
		i++;
	}
	return (-1);
}

int		julia_check(long double xt, long double yt, t_fract_params *p)
{
	int			i;
	int			maxi;
	long double m_x;
	long double m_y;
	long double xtt;

	i = 0;
	maxi = p->maxi;
	m_x = p->m_x;
	m_y = p->m_y;
	while (i < maxi)
	{
		xtt = xt;
		xt = xt * xt - yt * yt + m_x;
		yt = 2 * xtt * yt + m_y;
		if (xt * xt + yt * yt > 4)
			return (i);
		i++;
	}
	return (-1);
}
