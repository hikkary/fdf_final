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
	ft_putstr_fd("Value too big or not a number\n", 2);
	exit(EXIT_FAILURE);
}

void	not_number(void)
{
	ft_putstr_fd("Not a number \n", 2);
	exit(EXIT_FAILURE);
}

void isdig(char *str)
{
	int i;

	i = 0;
	if(str[0] == '-')
		i++;
	while(str[i] && str[i] != ',')
	{
		if(ft_isdigit(str[i]) == 0)
			not_number();
		i++;
	}
}


t_p		*ft_posxy(t_p *f, char ***t, int l, int h)
{
	int i;

	i = 0;
	f->zoom = 1980 / (f->i + f->len);
	f->zoomy =  1280 / (f->i + f->len);
	while (t[h])
	{
		while (t[h][l])
		{
			if (!(f->m[h][l] = (int *)malloc(sizeof(int) * 1)))
				exit(EXIT_FAILURE);
			if (ft_atoi(t[h][l]) > 100)
				ft_big();
			isdig(t[h][l]);
			f->m[h][l][0] = ft_atoi(t[h][l]);
			f->pos[h][l] = (int *)malloc(sizeof(int) * 1);
			f->posy[h][l] = (int *)malloc(sizeof(int) * 1);
			f->pos[h][l][0] = l * f->zoom + f->h / 25 + h * f->zoom;
			f->posy[h][l][0] = h * f->zoomy + f->l / 4 - f->m[h][l][0] * 5;
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
