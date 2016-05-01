/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   us_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:42:01 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/01/25 22:53:56 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_p		*zoom(t_p *f)
{
	f->zoom = 1980 / (f->i + f->len);
	f->zoomy = 1280 / (f->i + f->len);
	return (f);
}

t_p		*window(t_p *f)
{
	f->h = 1980;
	f->l = 1280;
	return (f);
}

void	too_small(void)
{
	ft_putstr_fd("Map too small\n", 2);
	exit(EXIT_FAILURE);
}

int		count_words(const char *str, char c)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			nbr++;
			i++;
		}
		else
			i++;
	}
	return (nbr);
}

int		***create_tab_int(int l, int c, int ***tab)
{
	int i;

	i = 0;
	tab = (int ***)malloc(sizeof(int **) * l + 1);
	if (tab)
	{
		while (i <= l)
		{
			tab[i] = (int **)malloc(sizeof(int *) * c + 1);
			i++;
		}
		tab[i] = NULL;
	}
	return (tab);
}
