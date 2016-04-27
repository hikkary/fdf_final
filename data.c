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

t_p	*stock(t_p *f, int fd, char **argv)
{
	char	*line;
	int		ret;

	f = malloc(sizeof(t_p));
	f->i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || get_next_line(fd, &line) == -1)
	{
		ft_putstr_fd("Unvalid file\n", 2);
		exit(1);
	}
	if (!(f->map = (char **)malloc(sizeof(char *) * 10000)))
		exit(EXIT_FAILURE);
	while ((ret = get_next_line(fd, &line) && ret != -1))
	{
		if (line[0] != ' ' && !ft_isdigit(line[0]))
			exit(EXIT_FAILURE);
		f->map[f->i] = ft_strnew(1);
		f->map[f->i] = ft_strjoin(f->map[f->i], line);
		free(line);
		f->i++;
	}
	f->len = count_words(f->map[0], ' ');
	f->map[f->i] = NULL;
	return (f);
}

t_p	*convint(t_p *f)
{
	int		i;

	i = 0;
	f->m = create_tab_int(f->i, f->len, f->m);
	f->pos = create_tab_int(f->i, f->len, f->m);
	f->posy = create_tab_int(f->i, f->len, f->m);
	f = stoi(f);
	return (f);
}
