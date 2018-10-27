/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraktol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 21:11:46 by tmarchen          #+#    #+#             */
/*   Updated: 2018/03/24 21:11:50 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	params_init(t_fract_params *fract_par)
{
	fract_par->x0 = -2.0;
	fract_par->x1 = 1.0;
	fract_par->y0 = -1.0;
	fract_par->y1 = 1.0;
	fract_par->maxi = 50;
	fract_par->m_x = 0.0;
	fract_par->m_y = 0.0;
}

void	usage(void)
{
	ft_putstr("\tusage: [ ./fractol n ] or [ ./fractol n n n+1 ... ]\n\
	n = {1-8} (number of set)\n\tsets:\n\t1 - Mandelbrot\n\
	2 - Julia\n\t3 - Tricorn\n\t4 - Buffalo\n\t5 - Celtic\n\t6 - Newton\n\
	7 - Julia2\n\t8 - Burnin\n");
}

void	pick_set(char *argv, t_fract_params *fract_par, void *par)
{
	int n;

	n = get_par(argv);
	if (n == 1)
		fract_par->check = zhopa_check;
	else if (n == 2)
		fract_par->check = julia_check;
	else if (n == 3)
		fract_par->check = tricorn_check;
	else if (n == 4)
		fract_par->check = buffalo_check;
	else if (n == 5)
		fract_par->check = celtic_check;
	else if (n == 6)
		fract_par->check = pool_check;
	else if (n == 7)
		fract_par->check = julia2_check;
	else if (n == 8)
		fract_par->check = burnin_check;
	else
	{
		usage();
		quit(par);
	}
}

void	prog(char *argv)
{
	t_all *all;

	all = (t_all*)mllc(sizeof(t_all));
	all->mlx_d = (t_mlx_d*)mllc(sizeof(t_mlx_d));
	(all->mlx_d)->mlx = mlx_init();
	(all->mlx_d)->window = mlx_new_window((all->mlx_d)->mlx, WX, WY, argv);
	(all->mlx_d)->img = (t_img*)mllc(sizeof(t_img));
	((all->mlx_d)->img)->img = mlx_new_image((all->mlx_d)->mlx, WX, WY);
	((all->mlx_d)->img)->data = (int*)mlx_get_data_addr(
	((all->mlx_d)->img)->img, &((all->mlx_d)->img)->bpp,
	&((all->mlx_d)->img)->sz, &((all->mlx_d)->img)->endian);
	all->fract_par = (t_fract_params*)mllc(sizeof(t_fract_params));
	params_init(all->fract_par);
	pick_set(argv, all->fract_par, all);
	zhopa((all->mlx_d)->img, all->fract_par);
	mlx_put_image_to_window((all->mlx_d)->mlx, (all->mlx_d)->window,
	((all->mlx_d)->img)->img, 0, 0);
	mlx_mouse_hook((all->mlx_d)->window, mouse, all);
	if ((all->fract_par)->check == julia_check ||
	(all->fract_par)->check == julia2_check)
		mlx_hook((all->mlx_d)->window, 6, (1L << 6), mouse_move, all);
	mlx_hook((all->mlx_d)->window, 2, 5, key, all);
	mlx_hook((all->mlx_d)->window, 17, 5, quit, all);
	mlx_loop((all->mlx_d)->mlx);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc > 1)
	{
		i = 0;
		while (++i < argc - 1)
		{
			if (!fork())
				execv(argv[0], (char *[]){ argv[0], argv[i], NULL });
		}
		prog(argv[i]);
	}
	else
		usage();
	return (0);
}
