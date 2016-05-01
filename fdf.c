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
	drawx(f, 0X00FF00);
	drawy(f, 0X00FF00);
	hub(f);
	mlx_key_hook(f->win, key_funct, 0);
	mlx_loop(f->mlx);
}

t_p		*size_m(t_p *f, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		bad_file();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != ' ' && ft_isdigit(line[0]) == 0)
			bad_file();
		free(line);
		f->size++;
	}
	if (ret < 0)
		bad_file();
	if (f->size <= 1)
		too_small();
	close(fd);
	return (f);
}

int		main(int argc, char **argv)
{
	int			fd;
	static t_p	*f;

	fd = 0;
	if (!argv[1])
	{
		ft_putstr_fd("No file\n", 2);
		return (-1);
	}
	if (argc != 2)
		return (-1);
	f = malloc(sizeof(t_p));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		bad_file();
	f = size_m(f, argv);
	f = stock(f, fd);
	f = window(f);
	f = convint(f);
	fdf(f);
	return (0);
}
