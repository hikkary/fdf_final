/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:09:12 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/04/28 00:23:56 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawx(t_p *f, int color)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (c <= f->i -1)
	{
		f->x1 = f->pos[c][i][0];
		f->y1 = f->posy[c][i][0];
		if (i + 1 <= f->len)
			f->x2 = f->pos[c][i + 1][0];
		if (i + 1 <= f->len )
			f->y2 = f->posy[c][i + 1][0];
		draw3(f, color, 0);
		i++;
		if (i == f->len && c <= f->i)
		{
			i = 0;
			c++;
		}
	}
}

void	drawy(t_p *f, int color)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (c < f->i - 1)
	{
		f->x1 = f->pos[c][i][0];
		f->y1 = f->posy[c][i][0];
		if (c != f->i)
			f->y2 = f->posy[c + 1][i][0];
		else if (c == f->i - 1 && i != f->len)
			f->y2 = f->posy[c][i + 1][0];
		if (c != f->i - 1 && c >= 0)
			f->x2 = f->pos[c + 1][i][0];
		else if (c == f->i - 1 && i != f->len)
			f->x2 = f->pos[c][i + 1][0];
		draw3(f, color, 0);
		i++;
		if (i == f->len + 1 && c < f->i - 1)
		{
			i = 0;
			c++;
		}
	}
}

void	draw3(t_p *f, int color, int sx)
{
	int sy;
	int e2;

	sy = f->y1 < f->y2 ? 1 : -1;
	sx = f->x1 < f->x2 ? 1 : -1;
	f->dx = abs(f->x2 - f->x1);
	f->dy = abs(f->y2 - f->y1);
	f->err = (f->dx > f->dy ? f->dx : -f->dy) / 2;
	while (42)
	{
		mlx_pixel_put(f->mlx, f->win, f->x1, f->y1, color);
		if (f->x1 == f->x2 && f->y1 == f->y2)
			break ;
		e2 = f->err;
		if (e2 > -f->dx)
		{
			f->err -= f->dy;
			f->x1 += sx;
		}
		if (e2 < f->dy)
		{
			f->err += f->dx;
			f->y1 += sy;
		}
	}
}
