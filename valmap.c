/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:56:30 by tmann             #+#    #+#             */
/*   Updated: 2019/02/18 15:42:44 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_valmap(char *strmap)
{
	int sim;
	int flag;
	int j;

	j = 0;
	sim = 0;
	flag = 0;
	while (strmap[j])
	{
		if (strmap[j] != ' ' && flag == 0)
		{
			sim++;
			flag = 1;
		}
		if (strmap[j] == ' ')
			flag = 0;
		if (strmap[j] == '\n')
		{
			flag = 0;
		}
		j++;
	}
	return (sim);
}

int			ft_checkline(char **strmap)
{
	int i;
	int sim;

	i = 0;
	sim = ft_valmap(strmap[i]);
	while (strmap[i])
	{
		if (ft_valmap(strmap[i]) == sim)
			i++;
		else
			return (0);
	}
	return (1);
}

void		ft_addcor(t_fdf *point, char *str, int i, int j)
{
	point->sys = 16;
	ft_check_alf(str, 0);
	point->sc[i][j].x = j;
	point->sc[i][j].y = i;
	point->sc[i][j].z = ft_atoi(str);
	point->sc[i][j].c = ft_color(str, point);
	point->sc[i][j].cs = ft_color(str, point);
	point->sys = 10;
	point->ssc[i][j].x = j;
	point->ssc[i][j].y = i;
	point->ssc[i][j].z = ft_atoi(str);
	point->ssc[i][j].c = ft_color(str, point) + 0xFF6600;
}

int			ft_color(char *str, t_fdf *po)
{
	char		strnew[1000];
	int			i;
	int			j;
	int			color;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			i += 3;
			while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
			{
				strnew[j] = str[i];
				j++;
				i++;
			}
			strnew[j] = '\0';
			return (color = ft_atoi_base(strnew, po->sys));
		}
		i++;
	}
	return (ft_atoi_base("33B1FF", 16));
}

void		ft_check_alf(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == ',')
		{
			i++;
			check16(str);
			break ;
		}
		else
		{
			write(1, "Wrong_character_in_coordinates\n", 32);
			exit(0);
		}
	}
	return ;
}
