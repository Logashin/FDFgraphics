/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funbres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:23:15 by tmann             #+#    #+#             */
/*   Updated: 2019/02/23 16:09:49 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		line(t_fdf *po)
{
	if (abs(po->y1 - po->y0) < abs(po->x1 - po->x0))
	{
		if (po->x0 > po->x1)
		{
			swapcor(po);
			linelow(po);
		}
		else
			linelow(po);
	}
	else
	{
		if (po->y0 > po->y1)
		{
			swapcor(po);
			linehigh(po);
		}
		else
			linehigh(po);
	}
}

void		addy(t_fdf *po)
{
	po->x0 = po->sc[po->i][po->j].x * po->start + po->end;
	po->y0 = po->sc[po->i][po->j].y * po->start + po->end2;
	po->x1 = po->sc[po->i + 1][po->j].x * po->start + po->end;
	po->y1 = po->sc[po->i + 1][po->j].y * po->start + po->end2;
	po->colx = po->sc[po->i][po->j].c;
}

void		addx(t_fdf *po)
{
	po->x0 = po->sc[po->i][po->j].x * po->start + po->end;
	po->y0 = po->sc[po->i][po->j].y * po->start + po->end2;
	po->x1 = po->sc[po->i][po->j + 1].x * po->start + po->end;
	po->y1 = po->sc[po->i][po->j + 1].y * po->start + po->end2;
	po->colx = po->sc[po->i][po->j].c;
}

void		linelow(t_fdf *po)
{
	int d;
	int y;

	po->dx = po->x1 - po->x0;
	po->dy = po->y1 - po->y0;
	po->yi = 1;
	if (po->dy < 0)
	{
		po->yi = -1;
		po->dy = -po->dy;
	}
	d = 2 * po->dy - po->dx;
	y = po->y0;
	while (po->x0 != po->x1)
	{
		if (po->y0 >= 0 && po->x0 >= 0 && po->y0 < SWIN && po->x0 < SWIN)
			po->data[po->x0 + po->y0 * SWIN] = po->colx;
		if (d > 0)
		{
			po->y0 = po->y0 + po->yi;
			d = d - 2 * po->dx;
		}
		d = d + 2 * po->dy;
		po->x0++;
	}
}

void		linehigh(t_fdf *po)
{
	int x;

	po->dx = po->x1 - po->x0;
	po->dy = po->y1 - po->y0;
	po->xi = 1;
	if (po->dx < 0)
	{
		po->xi = -1;
		po->dx = -po->dx;
	}
	po->d = 2 * po->dx - po->dy;
	x = po->x0;
	while (po->y0 != po->y1)
	{
		if (po->y0 >= 0 && po->x0 >= 0 && po->y0 < SWIN && po->x0 < SWIN)
			po->data[po->x0 + po->y0 * SWIN] = po->colx;
		if (po->d > 0)
		{
			po->x0 = po->x0 + po->xi;
			po->d = po->d - 2 * po->dy;
		}
		po->d = po->d + 2 * po->dx;
		po->y0++;
	}
}
