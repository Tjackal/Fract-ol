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

void	re(t_all *p)
{
	zhopa((p->mlx_d)->img, p->fract_par);
	mlx_put_image_to_window((p->mlx_d)->mlx, (p->mlx_d)->window,
	((p->mlx_d)->img)->img, 0, 0);
}

int		mouse(int button, int x, int y, void *par)
{
	t_all *p;

	p = (t_all*)par;
	if (button == 4)
	{
		scale(p->fract_par, x, y, 1);
		re(p);
	}
	else if (button == 5)
	{
		scale(p->fract_par, x, y, 0);
		re(p);
	}
	return (0);
}

int		key(int button, void *par)
{
	t_all *p;

	p = (t_all*)par;
	if (button == 53)
		quit(p);
	else if (button == 126 || button == 124 || button == 125 || button == 123)
	{
		move(p->fract_par, button);
		re(p);
	}
	else if (button == 69)
	{
		(p->fract_par)->maxi += 10;
		re(p);
	}
	else if (button == 78 && (((t_all*)p)->fract_par)->maxi > 0)
	{
		(p->fract_par)->maxi -= 10;
		re(p);
	}
	return (0);
}

int		mouse_move(int x, int y, void *par)
{
	t_all *p;

	p = (t_all*)par;
	(p->fract_par)->m_x = ((p->fract_par)->x0 + x * (p->fract_par)->stp_x);
	(p->fract_par)->m_y = ((p->fract_par)->y0 + y * (p->fract_par)->stp_y);
	re(p);
	return (0);
}

int		get_par(char *argv)
{
	int i;

	i = -1;
	while (argv[++i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (-1);
	}
	return (ft_atoi(argv));
}
