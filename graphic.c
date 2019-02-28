/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:45:52 by tmann             #+#    #+#             */
/*   Updated: 2019/02/26 15:23:48 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_graphic(t_fdf *po)
{
	po->mlx = mlx_init();
	po->win = mlx_new_window(po->mlx, SWIN, SWIN, "FDF");
	po->nim = mlx_new_image(po->mlx, SWIN, SWIN);
	po->data = (int*)mlx_get_data_addr(po->nim, &po->bpp,
		&po->line_size, &po->endian);
	centermap(po);
	ft_draw(po);
	mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
	po->stop = 0;
	po->colorstop = 0;
	mlx_hook(po->win, 2, 0, ft_keyboard, po);
	mlx_hook(po->win, 17, 0, ft_close, po);
	mlx_loop(po->mlx);
}

void		swapcor(t_fdf *po)
{
	int tmp;

	tmp = po->x0;
	po->x0 = po->x1;
	po->x1 = tmp;
	tmp = po->y0;
	po->y0 = po->y1;
	po->y1 = tmp;
}

void		ft_draw(t_fdf *po)
{
	po->i = 0;
	po->j = 0;
	while (po->i < po->sizearr2)
	{
		while (po->j < po->sizearr2l)
		{
			if (po->j + 1 < po->sizearr2l)
			{
				addx(po);
				line(po);
			}
			if (po->i + 1 < po->sizearr2)
			{
				addy(po);
				line(po);
			}
			po->j++;
		}
		po->j = 0;
		po->i++;
	}
}

void		ft_draw_z(t_fdf *po)
{
	po->i = 0;
	po->j = 0;
	while (po->i < po->sizearr2)
	{
		po->j = 0;
		while (po->j < po->sizearr2l)
		{
			iso(po);
			po->j++;
		}
		po->i++;
	}
}

void		iso(t_fdf *po)
{
	int previous_x;
	int previous_y;

	previous_x = (int)(po->sc[po->i][po->j].x);
	previous_y = (int)(po->sc[po->i][po->j].y);
	po->sc[po->i][po->j].x = (previous_x - previous_y) * cos(0.523599);
	po->sc[po->i][po->j].y = -po->sc[po->i][po->j].z +
		(previous_x + previous_y) * sin(0.523599);
}
