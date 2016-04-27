/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:15:07 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/02/01 16:32:41 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		bn(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' || buf[i] == EOF)
			return (i);
		i++;
	}
	return (0);
}

char	*lire(t_g *s, int fd, char **line)
{
	if (s->an != NULL)
	{
		line[0] = ft_strjoin(line[0], s->an);
		s->an = NULL;
	}
	while ((s->ret = read(fd, s->buf, BUFF_SIZE)))
	{
		if (s->ret == -1)
			return (NULL);
		s->buf[s->ret] = '\0';
		line[0] = ft_strjoin(line[0], s->buf);
		if (ft_strchr(line[0], '\n'))
		{
			s->an = ft_strchr(line[0], '\n');
			s->an++;
			line[0] = ft_strsub(line[0], 0, bn(line[0]));
			return (line[0]);
		}
	}
	return (line[0]);
}

int		after_n(t_g *s, char **line)
{
	if (s->an)
	{
		if (ft_strchr(s->an, '\n'))
		{
			line[0] = ft_strsub(s->an, 0, bn(s->an));
			s->an = ft_strchr(s->an, '\n');
			s->an++;
			if (*s->an == '\0')
			{
				s->an = NULL;
				free(s->an);
				return (1);
			}
			else
				return (1);
		}
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_g *s;

	if (fd < 0 || fd > 256 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!s)
	{
		s = malloc(sizeof(t_g));
		s->an = NULL;
	}
	line[0] = ft_strnew(1);
	if (after_n(s, &line[0]))
		return (1);
	if (line[0])
		line[0] = lire(s, fd, &line[0]);
	if (line[0] == NULL)
		return (-1);
	if (line[0][0] == '\0' && s->ret == 0)
		return (0);
	else
		return (1);
}
