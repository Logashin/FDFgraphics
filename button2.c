/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:24:21 by tmann             #+#    #+#             */
/*   Updated: 2019/02/26 15:23:08 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		button2(t_fdf *po, int button)
{
	if (button == 123 || button == 124)
		runmapx(po, button);
	if (button == 125 || button == 126)
		runmapy(po, button);
	if (button == 69 || button == 78)
		zoom(po, button);
	if (button == 2)
		rotatey(po);
	if (button == 0)
		rotatey2(po);
	if (button == 12)
		rotatez(po);
	if (button == 14)
		rotatez2(po);
}

void		runmapx(t_fdf *po, int button)
{
	if (button == 124)
	{
		ft_bzero(po->data, SWIN * SWIN * 4);
		mlx_clear_window(po->mlx, po->win);
		po->end = po->end + 10;
		ft_draw(po);
		mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
	}
	if (button == 123)
	{
		ft_bzero(po->data, SWIN * SWIN * 4);
		mlx_clear_window(po->mlx, po->win);
		po->end = po->end - 10;
		ft_draw(po);
		mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
	}
}

void		runmapy(t_fdf *po, int button)
{
	if (button == 125)
	{
		ft_bzero(po->data, SWIN * SWIN * 4);
		mlx_clear_window(po->mlx, po->win);
		po->end2 = po->end2 + 10;
		ft_draw(po);
		mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
	}
	if (button == 126)
	{
		ft_bzero(po->data, SWIN * SWIN * 4);
		mlx_clear_window(po->mlx, po->win);
		po->end2 = po->end2 - 10;
		ft_draw(po);
		mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
	}
}

void		zoom(t_fdf *po, int button)
{
	if (button == 69)
	{
		ft_bzero(po->data, SWIN * SWIN * 4);
		mlx_clear_window(po->mlx, po->win);
		po->start = po->start + 1;
		po->end = po->end - 1;
		ft_draw(po);
		mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
	}
	if (button == 78)
	{
		ft_bzero(po->data, SWIN * SWIN * 4);
		mlx_clear_window(po->mlx, po->win);
		if (po->start > 1)
		{
			po->start = po->start - 1;
			po->end = po->end + 1;
		}
		ft_draw(po);
		mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
	}
}

void		rotatey(t_fdf *po)
{
	float str[po->sizearr2][po->sizearr2l];

	po->i = 0;
	po->j = 0;
	while (po->i < po->sizearr2)
	{
		while (po->j < po->sizearr2l)
		{
			str[po->i][po->j] = po->sc[po->i][po->j].x *
				cos(0.1) + po->sc[po->i][po->j].z * sin(0.1);
			po->sc[po->i][po->j].z = -po->sc[po->i][po->j].x *
				sin(0.1) + po->sc[po->i][po->j].z * cos(0.1);
			po->sc[po->i][po->j].x = str[po->i][po->j];
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
