/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:08:54 by tmann             #+#    #+#             */
/*   Updated: 2019/02/23 16:04:51 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		colorin10(t_fdf *po)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (i < po->sizearr2)
	{
		while (j < po->sizearr2l)
		{
			po->sc[i][j].c = po->ssc[i][j].c;
			j++;
		}
		i++;
		j = 0;
	}
}

void		colorin16(t_fdf *po)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (i < po->sizearr2)
	{
		while (j < po->sizearr2l)
		{
			po->sc[i][j].c = po->sc[i][j].cs;
			j++;
		}
		i++;
		j = 0;
	}
}

void		button8(t_fdf *po)
{
	if (po->colorstop == 0)
	{
		ft_bzero(po->data, SWIN * SWIN * 4);
		mlx_clear_window(po->mlx, po->win);
		colorin10(po);
		ft_draw(po);
		mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
		po->colorstop = 1;
	}
	else
	{
		ft_bzero(po->data, SWIN * SWIN * 4);
		mlx_clear_window(po->mlx, po->win);
		colorin16(po);
		ft_draw(po);
		mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
		po->colorstop = 0;
	}
}

void		button15(t_fdf *po)
{
	po->pressr = 1;
	ft_bzero(po->data, SWIN * SWIN * 4);
	mlx_clear_window(po->mlx, po->win);
	startcor(po);
	centermap(po);
	ft_draw(po);
	mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
	po->stop = 0;
	po->pressr = 0;
}

void		rotatez(t_fdf *po)
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
				cos(0.1) - po->sc[po->i][po->j].y * sin(0.1);
			stry[po->i][po->j] = po->sc[po->i][po->j].x *
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
