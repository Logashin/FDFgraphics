/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:51:01 by tmann             #+#    #+#             */
/*   Updated: 2019/02/17 21:03:23 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		*ft_scanmap(char *argv, t_fdf *point, int count, int i)
{
	char	**str;
	char	**nstr;
	int		j;

	j = 0;
	str = readmap(argv, 0, 0, NULL);
	point = ft_joincor(str, 0);
	while (str[i] != '\0')
	{
		count = ft_countword(str[i], ' ');
		point->sizearr2l = count;
		nstr = ft_strsplit(str[i], ' ');
		point->ssc[i] = (t_cor*)malloc(sizeof(t_cor) * (count));
		point->sc[i] = (t_cor*)malloc(sizeof(t_cor) * (count));
		while (nstr[j] != '\0')
		{
			ft_addcor(point, nstr[j], i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (point);
}

char		**readmap(char *argv, int fd, int nb, char *tmp)
{
	char	strbuf[BF + 1];
	char	*strmap;
	char	**twoarr;

	strmap = ft_strnew(0);
	fd = open(argv, O_RDONLY);
	if (fd < 0 || argv == NULL || read(fd, strbuf, 0) < 0)
	{
		write(1, "Bad_file\n", 9);
		free(strmap);
		exit(0);
	}
	while ((nb = read(fd, strbuf, BF)) > 0)
	{
		strbuf[nb] = '\0';
		tmp = strmap;
		strmap = ft_strjoin(strmap, strbuf);
		free(tmp);
	}
	if (nb < 0 || strmap[0] == '\0' || strmap[1] == '\0')
	{
		write(1, "Need_more_coordinates\n", 23);
		exit(0);
	}
	return (twoarr = creattwoarr(strmap));
}

char		**creattwoarr(char *str)
{
	char		**strnew;
	int			i;
	int			j;

	j = 0;
	i = 0;
	strnew = ft_strsplit(str, '\n');
	free(str);
	if ((ft_checkline(strnew)) == 0)
	{
		write(1, "Wrong_coordinates\n", 19);
		free(strnew);
		exit(0);
	}
	return (strnew);
}

t_fdf		*ft_joincor(char **str, int count)
{
	t_fdf *head;

	if (!(head = malloc(sizeof(t_fdf))))
		exit(0);
	while (str[count])
		count++;
	head->sizearr2 = count;
	if (!(head->sc = (t_cor**)malloc(sizeof(t_cor*) * (count + 1))))
		exit(0);
	if (!(head->ssc = (t_cor**)malloc(sizeof(t_cor*) * (count + 1))))
		exit(0);
	return (head);
}

void		startcor(t_fdf *po)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (i < po->sizearr2)
	{
		while (j < po->sizearr2l)
		{
			po->sc[i][j].x = po->ssc[i][j].x;
			po->sc[i][j].y = po->ssc[i][j].y;
			po->sc[i][j].z = po->ssc[i][j].z;
			if (po->pressr == 1)
				po->sc[i][j].c = po->sc[i][j].cs;
			j++;
		}
		i++;
		j = 0;
	}
}
