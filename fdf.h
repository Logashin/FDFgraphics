/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:46:46 by tmann             #+#    #+#             */
/*   Updated: 2019/02/23 21:35:00 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BF 10000
# define SWIN 1000
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_cor
{
	double			x;
	double			y;
	double			z;
	int				c;
	int				cs;
}					t_cor;

typedef struct		s_fdf
{
	t_cor			**sc;
	t_cor			**ssc;
	int				sizearr2l;
	int				sizearr2;
	int				dx;
	int				dy;
	int				yi;
	int				i;
	int				j;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	void			*mlx;
	void			*win;
	void			*nim;
	int				*data;
	int				bpp;
	int				line_size;
	int				endian;
	int				colx;
	int				coly;
	int				d;
	int				xi;
	int				start;
	int				end;
	int				end2;
	float			sizeline_x;
	float			centerfigurx;
	float			otstupx;
	float			centerfigury;
	float			sizeline_y;
	float			otstupy;
	int				sys;
	int				stop;
	int				colorstop;
	int				pressr;
}					t_fdf;

t_fdf				*ft_scanmap(char *argv, t_fdf *point, int count, int i);
char				**readmap(char *argv, int fd, int nb, char *tmp);
char				**creattwoarr(char *str);
int					ft_valmap(char *strmap);
int					ft_checkline(char **strmap);
t_fdf				*ft_joincor(char **str, int count);
void				ft_addcor(t_fdf *point, char *str, int i, int j);
int					ft_color(char *str, t_fdf *po);
void				ft_check_alf(char *str, int i);
void				check16(char *str);
int					check16p2(char *str);
int					ft_atoi_base(const char *str, int base);
void				ft_graphic(t_fdf *po);
void				ft_draw(t_fdf *po);
void				line(t_fdf *po);
void				addx(t_fdf *po);
void				addy(t_fdf *po);
void				linelow(t_fdf *po);
void				linehigh(t_fdf *po);
void				swapcor(t_fdf *po);
int					ft_keyboard(int button, t_fdf *po);
int					ft_close (void *param);
void				centermap(t_fdf *po);
void				ft_draw_z(t_fdf *po);
void				iso(t_fdf *po);
void				startcor(t_fdf *po);
void				centeriso(t_fdf *po);
void				ft_keyboard2(t_fdf *po, int button);
void				colorin10(t_fdf *po);
void				colorin16(t_fdf *po);
void				button8(t_fdf *po);
void				button15(t_fdf *po);
void				button2(t_fdf *po, int button);
void				runmapx(t_fdf *po, int button);
void				runmapy(t_fdf *po, int button);
void				zoom(t_fdf *po, int button);
void				rotatex2(t_fdf *po, int button);
void				rotatex(t_fdf *po, int button);
void				rotatey(t_fdf *po);
void				rotatey2(t_fdf *po);
void				rotatez(t_fdf *po);
void				rotatez2(t_fdf *po);
int					nbrbase(const char *str, int base, int res, int i);

#endif
