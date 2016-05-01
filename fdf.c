/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:06:53 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/02/07 23:18:22 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p		*window(t_p *f)
{
	f->h = 1980;
	f->l = 1280;
	return (f);
}

void	hub(t_p *f)
{
	mlx_string_put(f->mlx, f->win, 35, 35, 0x0000FF, " Exit");
	mlx_string_put(f->mlx, f->win, 85, 35, 0xFFFFFF, " = ");
	mlx_string_put(f->mlx, f->win, 110, 35, 0xFF0000, " Esc ");
}

int		key_funct(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

void	fdf(t_p *f)
{
	int i;
	int c;

	c = 0;
	i = 0;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->h, f->l, "fdf");
	DEBUG
	drawx(f, 0X00FF00);
	DEBUG
	drawy(f, 0X00FF00);
	DEBUG
	hub(f);
	DEBUG
	mlx_key_hook(f->win, key_funct, 0);
	mlx_loop(f->mlx);
}

int		main(int argc, char **argv)
{
	int			fd;
	static t_p	*f;

	fd = 0;
	DEBUG
	if (!argv[1])
	{
		ft_putstr_fd("No file\n", 2);
		return (-1);
	}
	DEBUG
	if (argc != 2)
		return (-1);
	DEBUG
	f = stock(f, fd, argv);
	DEBUG
	if (f->i <= 3)
	{
		ft_putstr_fd("Map too small", 2);
		exit(EXIT_FAILURE);
	}
	f = window(f);
	DEBUG
	f = convint(f);
	fdf(f);
	return (0);
}
