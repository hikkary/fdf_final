/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:20:35 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/02/07 22:39:24 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct	s_param
{
	char	**map;
	void	*mlx;
	void	*win;
	int		***m;
	int		***pos;
	int		***posy;
	int		err;
	int		dp;
	int		de;
	int		dne;
	int		x;
	int		y;
	int		dy;
	int		dx;
	int		y1;
	int		x1;
	int		y2;
	int		x2;
	int		ld;
	int		lg;
	int		h;
	int		l;
	int		i;
	int		len;
	int		lline;
	int		zoom;
}				t_p;

t_p				*stock(t_p *f, int fd, char **argv);
int				***create_tab_int(int l, int c, int ***tab);
int				count_words(const char *str, char c);
void			fdf(t_p *f);
t_p				*stock(t_p *f, int fd, char **argv);
t_p				*convint(t_p *f);
void			draw3(t_p *f, int color, int sx);
t_p				*stoi(t_p *f);
void			drawx(t_p *f, int color);
void			drawy(t_p *f, int color);
t_p				*ft_posxy(t_p *f, char ***t, int l, int h);
void			ft_big();
#endif
