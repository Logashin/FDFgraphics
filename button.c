/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:13:28 by tmann             #+#    #+#             */
/*   Updated: 2019/02/24 19:45:34 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_keyboard(int button, t_fdf *po)
{
	if (button == 53)
	{
		free(po->win);
		free(po->mlx);
		free(po);
		exit(0);
	}
	if (button == 49)
		ft_keyboard2(po, button);
	else if (button == 15)
		button15(po);
	else if (button == 8)
		button8(po);
	else if (button == 1)
		rotatex(po, button);
	else if (button == 13)
		rotatex2(po, button);
	else
		button2(po, button);
	return (0);
}

void		ft_keyboard2(t_fdf *po, int button)
{
	if (button == 49)
	{
		if (po->stop == 0)
		{
			ft_bzero(po->data, SWIN * SWIN * 4);
			mlx_clear_window(po->mlx, po->win);
			ft_draw_z(po);
			ft_draw(po);
			mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
			po->stop = 1;
		}
		else
		{
			ft_bzero(po->data, SWIN * SWIN * 4);
			mlx_clear_window(po->mlx, po->win);
			startcor(po);
			ft_draw(po);
			mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);
			po->stop = 0;
		}
	}
}

void		rotatex(t_fdf *po, int button)
{
	float str[po->sizearr2][po->sizearr2l];

	if (button == 1)
	{
		po->i = 0;
		po->j = 0;
		while (po->i < po->sizearr2)
		{
			while (po->j < po->sizearr2l)
			{
				str[po->i][po->j] = po->sc[po->i][po->j].y *
					cos(0.1) + po->sc[po->i][po->j].z * sin(0.1);
				po->sc[po->i][po->j].z = -po->sc[po->i][po->j].y *
					sin(0.1) + po->sc[po->i][po->j].z * cos(0.1);
				po->sc[po->i][po->j].y = str[po->i][po->j];
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
}

void		rotatex2(t_fdf *po, int button)
{
	float str[po->sizearr2][po->sizearr2l];

	po->i = 0;
	po->j = 0;
	if (button == 13)
	{
		while (po->i < po->sizearr2)
		{
			while (po->j < po->sizearr2l)
			{
				str[po->i][po->j] = po->sc[po->i][po->j].y *
					cos(0.1) - po->sc[po->i][po->j].z * sin(0.1);
				po->sc[po->i][po->j].z = po->sc[po->i][po->j].y *
					sin(0.1) + po->sc[po->i][po->j].z * cos(0.1);
				po->sc[po->i][po->j].y = str[po->i][po->j];
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
}

void		rotatey2(t_fdf *po)
{
	float str[po->sizearr2][po->sizearr2l];

	po->i = 0;
	po->j = 0;
	while (po->i < po->sizearr2)
	{
		while (po->j < po->sizearr2l)
		{
			str[po->i][po->j] = po->sc[po->i][po->j].x *
				cos(0.1) - po->sc[po->i][po->j].z * sin(0.1);
			po->sc[po->i][po->j].z = po->sc[po->i][po->j].x *
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
