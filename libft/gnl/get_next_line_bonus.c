/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:25:56 by gule-bat          #+#    #+#             */
/*   Updated: 2025/01/17 17:25:56 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>

char	*ft_calloc(size_t nitems, size_t size)
{
	void			*str;
	size_t			total;
	size_t			index;
	unsigned char	*st;

	if (size == 0 || nitems == 0)
		return (NULL);
	index = 0;
	str = NULL;
	st = NULL;
	total = nitems * size;
	str = malloc(total);
	if (!str || total <= 0)
		return (free(str), free(st), NULL);
	st = str;
	while (nitems)
	{
		st[index] = (char) '\0';
		index++;
		nitems--;
	}
	return (str);
}

char	*ft_stash(char *stash, char *st)
{
	char	*temp;
	int		i;

	i = BUFFER_SIZE;
	if (!stash || !st)
		return (NULL);
	temp = ft_strjoin(stash, st);
	if (!temp)
		return (free(stash), NULL);
	free(stash);
	while (i--)
		st[i] = '\0';
	stash = NULL;
	return (temp);
}

char	*read_n_stock(char *rest, int fd)
{
	int		sd;
	char	*rd;

	sd = -1;
	rd = NULL;
	rd = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!rd)
		return (free(rd), NULL);
	while (sd != 0)
	{
		sd = read(fd, rd, BUFFER_SIZE);
		if (sd <= 0)
		{
			if ((sd == 0 || sd < BUFFER_SIZE) && (rd[0] || rest[0]))
				return (free(rd), rest);
			return (free(rd), free(rest), NULL);
		}
		rest = ft_stash(rest, rd);
		if (!rest)
			return (free(rd), free(rest), NULL);
		if (n_in_str(rest, 0))
			break ;
	}
	free(rd);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*line;
	char		*stock;

	line = NULL;
	stock = NULL;
	if ((fd < 0 || fd > 1024) || (BUFFER_SIZE <= 0)
		|| read(fd, NULL, 0) == -1)
		return (free(rest[fd]), rest[fd] = NULL, NULL);
	if (!rest[fd])
		rest[fd] = ft_calloc(1, sizeof(char));
	if (!rest[fd])
		return (free(rest[fd]), NULL);
	if (!n_in_str(rest[fd], 0))
		rest[fd] = read_n_stock(rest[fd], fd);
	if (!rest[fd])
		return (free(rest[fd]), free(stock), NULL);
	line = ft_strwithorn(rest[fd], 1);
	if (!line)
		return (free(line), free(rest[fd]), NULL);
	stock = rest[fd];
	rest[fd] = ft_strwithorn(stock, 2);
	free(stock);
	return (line);
}
