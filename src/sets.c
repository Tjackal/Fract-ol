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

int		buffalo_check(long double x, long double y, t_fract_params *p)
{
	int			i;
	int			maxi;
	long double xt;
	long double yt;
	long double xtt;

	i = 0;
	maxi = p->maxi;
	xt = 0;
	yt = 0;
	while (i < maxi)
	{
		xtt = xt;
		xt = fabsl(xt * xt - yt * yt) + x;
		yt = -2 * fabsl(xtt * yt) + y;
		if (xt * xt + yt * yt > 4)
			return (i);
		i++;
	}
	return (-1);
}

int		tricorn_check(long double x, long double y, t_fract_params *p)
{
	int			i;
	int			maxi;
	long double xt;
	long double yt;
	long double xtt;

	i = 0;
	maxi = p->maxi;
	xt = 0;
	yt = 0;
	while (i < maxi)
	{
		xtt = xt;
		xt = xt * xt - yt * yt + x;
		yt = -2 * xtt * yt + y;
		if (xt * xt + yt * yt > 4)
			return (i);
		i++;
	}
	return (-1);
}

int		celtic_check(long double x, long double y, t_fract_params *p)
{
	int			i;
	int			maxi;
	long double xt;
	long double yt;
	long double xtt;

	i = 0;
	maxi = p->maxi;
	xt = 0;
	yt = 0;
	while (i < maxi)
	{
		xtt = xt;
		xt = fabsl(xt * xt - yt * yt) + x;
		yt = 2 * xtt * yt + y;
		if (xt * xt + yt * yt > 4)
			return (i);
		i++;
	}
	return (-1);
}

int		burnin_check(long double x, long double y, t_fract_params *p)
{
	int			i;
	int			maxi;
	long double xt;
	long double yt;
	long double xtt;

	i = 0;
	maxi = p->maxi;
	xt = 0;
	yt = 0;
	while (i < maxi)
	{
		xtt = xt;
		xt = xt * xt - yt * yt + x;
		yt = -2 * xtt * fabsl(yt) + y;
		if (xt * xt + yt * yt > 4)
			return (i);
		i++;
	}
	return (-1);
}

int		zhopa_check(long double x, long double y, t_fract_params *p)
{
	int			i;
	int			maxi;
	long double xt;
	long double yt;
	long double xtt;

	i = 0;
	maxi = p->maxi;
	xt = 0;
	yt = 0;
	while (i < maxi)
	{
		xtt = xt;
		xt = xt * xt - yt * yt + x;
		yt = 2 * xtt * yt + y;
		if (xt * xt + yt * yt > 4)
			return (i);
		i++;
	}
	return (-1);
}
