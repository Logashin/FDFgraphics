/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:22:41 by tmann             #+#    #+#             */
/*   Updated: 2019/02/01 18:18:19 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf *point;
	// void *mlx;
	// void *win;
	// void *nim;
	// int *data;
	// int bpp;
	// int line_size;
	// int endian;
	point = NULL;
	if (argc == 2)
	{	
		ft_scanmap(argv[1], point, 0);
		// mlx = mlx_init();
		// win = mlx_new_window(mlx, 1920, 1080, "FDF");
		// nim = mlx_new_image(mlx, 1920, 1080);
		// data = (int*)mlx_get_data_addr(nim, &bpp, &line_size, &endian);
		// 	data[10000] = 0xFF2E7F;
		// mlx_put_image_to_window(mlx, win, nim, 0, 0);
		// mlx_loop(mlx);
	}
	if (argc == 1)
		write(1, "Select_file\n", 12);
	if (argc > 2)
		write(1, "Select_one_file\n", 16);
	return (0);
}


// t_fdf   *creatlist(t_fdf *list)
// {
// list = (t_fdf*)malloc(sizeof(t_fdf));
// if (!list)
//     return (0);
//     //  list->coord;
//     return (list);
// }