/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:58:30 by tmann             #+#    #+#             */
/*   Updated: 2019/02/23 21:38:03 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check16(char *str)
{
	int i;

	i = check16p2(str);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] >= 'a' && str[i] <= 'f')
			i++;
		else if (str[i] >= 'A' && str[i] <= 'F')
			i++;
		else
		{
			write(1, "Enter_color_in_16th_system\n", 28);
			free(str);
			exit(0);
		}
	}
	return ;
}

int			check16p2(char *str)
{
	int i;

	i = 0;
	while (str[i] != ',' && str[i] != '\0')
		i++;
	i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	else
	{
		write(1, "Color_should_start_with_0x\n", 28);
		free(str);
		exit(0);
	}
	if (str[i + 1] == '\0')
	{
		write(1, "No_color_selected\n", 19);
		free(str);
		exit(0);
	}
	return (i);
}

int			nbrbase(const char *str, int base, int res, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * base + str[i] - 48;
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res * base + str[i] - 55;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res * base + str[i] - 87;
		i++;
	}
	return (res);
}

int			ft_atoi_base(const char *str, int base)
{
	int i;
	int res;
	int otr;

	if (!str[0] || (base < 2 || base > 16))
		return (0);
	i = 0;
	res = 0;
	otr = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		otr = -1;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = nbrbase(str, base, res, i);
	return (otr * res);
}

void		centermap(t_fdf *po)
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
