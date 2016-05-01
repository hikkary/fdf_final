/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:05:25 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/02/07 21:29:19 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void bad_file()
{
	ft_putstr_fd("Unvalid file\n", 2);
		exit(EXIT_FAILURE);
}

void bad_map()
{
	ft_putstr_fd("Unvalid/Not square map\n", 2);
		exit(EXIT_FAILURE);
}

void too_small()
{
	ft_putstr_fd("Map too small\n", 2);
		exit(EXIT_FAILURE);
}

void ft_ismap(char **str)
{
	int i;
	int len;
	int ver;
	i = 1;
	ver = 0;
	len = count_words(str[0], ' ');
	while(str[i])
	{
		ver = count_words(str[i], ' ');
		if(ver != len)
			bad_map();
		i++;
	}
}



t_p	*stock(t_p *f, int fd)
{
	char	*line;
	int		ret;

	f->i = 0;
	if (!(f->map = (char **)malloc(sizeof(char *) * f->size + 1)))
		exit(EXIT_FAILURE);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != ' ' && ft_isdigit(line[0] == 0))
		  	exit(EXIT_FAILURE);
		f->map[f->i] = ft_strnew(1);
		f->map[f->i] = ft_strjoin(f->map[f->i], line);
		free(line);
		f->i++;
	}
	if (ret < 0)
		bad_file();
	if(f->i <= 1 || (f->len = count_words(f->map[0], ' ')) <= 1) 
		too_small();
	ft_ismap(f->map);
	f->map[f->i] = NULL;
	close(fd);
	return (f);
}

t_p	*convint(t_p *f)
{
	int		i;

	i = 0;
	f->len = f->len - 1;
	f->m = create_tab_int(f->i, f->len, f->m);
	f->pos = create_tab_int(f->i, f->len, f->m);
	f->posy = create_tab_int(f->i, f->len, f->m);
	f = stoi(f);
	return (f);
}
