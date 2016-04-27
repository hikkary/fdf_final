/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:15:40 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/02/07 22:07:07 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_big(void)
{
	ft_putstr_fd("Value too big\n", 2);
	exit(1);
}

t_p		*ft_posxy(t_p *f, char ***t, int l, int h)
{
	int i;

	i = 0;
	f->zoom = (f->h - f->l) / f->len;
	while (t[h])
	{
		while (t[h][l])
		{
			if (!(f->m[h][l] = (int *)malloc(sizeof(int) * 1)))
				exit(EXIT_FAILURE);
			if (ft_atoi(t[h][l]) > 100)
				ft_big();
			f->m[h][l][0] = ft_atoi(t[h][l]);
			f->pos[h][l] = (int *)malloc(sizeof(int) * 1);
			f->posy[h][l] = (int *)malloc(sizeof(int) * 1);
			f->pos[h][l][0] = l * f->zoom + f->h / 4 + h * f->zoom;
			f->posy[h][l][0] = h * f->zoom + f->l / 2 - f->m[h][l][0] * 5;
			l++;
			i++;
		}
		l = 0;
		h++;
	}
	return (f);
}

t_p		*stoi(t_p *f)
{
	int		l;
	char	***t;

	l = 0;
	if (!(t = (char ***)malloc(sizeof(char **) * f->i + 1)))
		exit(EXIT_FAILURE);
	while (f->map[l])
	{
		t[l] = ft_strsplit(f->map[l], ' ');
		l++;
	}
	f = ft_posxy(f, t, 0, 0);
	return (f);
}
