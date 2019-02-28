/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:25:36 by tmann             #+#    #+#             */
/*   Updated: 2019/02/01 18:52:20 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_free_array(char **str, int i)
{
	while (i)
		free(str[i--]);
	return (NULL);
}

int		ft_calc_words(char const *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (i);
}

int		ft_calc_letters(char const *s, char c)
{
	int i;

	while (*s)
	{
		i = 0;
		if (*s != c && *s)
		{
			while (*s != c && *s)
			{
				s++;
				i++;
			}
			return (i);
		}
		if (*s)
			s++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;

	if (!s || !c)
		return (NULL);
	i = 0;
	str = (char**)malloc(sizeof(str) * (ft_calc_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		if (*s != c && *s)
		{
			str[i] = ft_strnew(ft_calc_letters(s, c));
			if (!str[i])
				return (ft_free_array(str, i));
			ft_strncpy(str[i++], s, ft_calc_letters(s, c));
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	str[i] = NULL;
	return (str);
}
