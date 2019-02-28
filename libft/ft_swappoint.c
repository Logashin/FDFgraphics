/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swappoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:00:28 by tmann             #+#    #+#             */
/*   Updated: 2018/12/27 20:32:48 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swappoint(void **a, void **b)
{
	unsigned char	**p;
	unsigned char	**q;
	unsigned char	*tmp;

	if (!a || !b)
		return ;
	p = (unsigned char**)a;
	q = (unsigned char**)b;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
