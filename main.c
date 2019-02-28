/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:22:41 by tmann             #+#    #+#             */
/*   Updated: 2019/02/23 16:11:13 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotatez2(t_fdf *po)
{
	float strx[po->sizearr2][po->sizearr2l];
	float stry[po->sizearr2][po->sizearr2l];

	po->i = 0;
	po->j = 0;
	while (po->i < po->sizearr2)
	{
		while (po->j < po->sizearr2l)
		{
			strx[po->i][po->j] = po->sc[po->i][po->j].x *
				cos(0.1) + po->sc[po->i][po->j].y * sin(0.1);
			stry[po->i][po->j] = -po->sc[po->i][po->j].x *
				sin(0.1) + po->sc[po->i][po->j].y * cos(0.1);
			po->sc[po->i][po->j].x = strx[po->i][po->j];
			po->sc[po->i][po->j].y = stry[po->i][po->j];
			po->j++;
		}
		po->i++;
		po->j = 0;
	}
	ft_bzero(po->data, SWIN * SWIN * 4);
	mlx_clear_window(po->mlx, po->win);
	ft_draw(po);
	mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
}

void		centeriso(t_fdf *po)
{
	po->sizeline_x = SWIN / (po->sizearr2l + po->sizearr2);
	po->sizeline_y = SWIN / (po->sizearr2l + po->sizearr2);
	po->centerfigurx = (po->sizeline_x * (po->sizearr2 - 1)) / 2;
	po->centerfigury = (po->sizeline_y * (po->sizearr2l - 1)) / 2;
	po->otstupx = po->centerfigurx + po->sizeline_x;
	po->otstupy = po->centerfigury + po->sizeline_y;
	po->start = po->sizeline_x;
	po->end = po->otstupx;
	po->end2 = po->otstupy;
}

int			ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fdf *point;
	t_fdf *start;

	start = NULL;
	point = NULL;
	if (argc == 2)
	{
		point = ft_scanmap(argv[1], point, 0, 0);
		ft_graphic(point);
	}
	if (argc == 1)
		write(1, "Select_file\n", 12);
	if (argc > 2)
		write(1, "Select_one_file\n", 16);
	return (0);
}
