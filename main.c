/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:08:43 by gule-bat          #+#    #+#             */
/*   Updated: 2025/05/10 17:08:43 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "./libft/libft.h"
#include "./libft/get_next_line.h"

// PLAYING:
//
// https://www.youtube.com/watch?v=cO401nm560c
// https://open.spotify.com/intl-fr/album/2KocdPCb97uWIdR1Ltq4qI?si=liFpFOZXQvOceZFqLIhmNA
// https://open.spotify.com/album/6EZXwfwYYfU9YfxM0Gv6ZN?si=VdYRwiqMTgKdYIRVY4I37A 
// https://open.spotify.com/playlist/2H9SBEN4XxRCqtQ7xrmlGT?si=b9e8a59bd7154db6
//


// typedef struct s_colorval {
// 	char	***colorshex;


// } 				colorval;

char	**get_colors_xpm(char *file, int *size)
{
	char    *str;
	char	**colors;
	int     fd;
	int		i;
	str = NULL;
	colors = NULL;
	i = 0;
	fd = open(file, O_RDONLY);
	colors = ft_calloc(size[2]+1,(sizeof(char *)));
	ft_bzero(colors, size[2]+1);
	while (i < 256)
	{
		str = get_next_line(fd);
		// printf("%s\n", str);
		if (str == NULL)
			break ;
		if (ft_strncmp(&str[4], "c #", 2) == 0)
			colors[i++] = str;
		else
			free(str);
	}
	colors[i] = NULL;
	close(fd);
	return (colors);
}

// void	color

void	colortohex(char **colors, char x, char y, int m)
{
	// char	***colorhex;
	int		i;
	int		j;
	int		color;
	int		r;
	int		g;
	int		b;

	i = 0;
	j = 0;
	(r = (g = (b = 0)));
	color = 0;
	if (!x || !y)
		return ;
	while (colors[i] != NULL)
	{
		j = 0;
		if (colors[i][j+1] == x && colors[i][j+2] == y)
		{
			j += 2;
			while (colors[i][j] != '#')
				j++;
			color = (int)strtol(&colors[i][j]+1, NULL, 16);
			r = (color >> 16) & 0xFF;
			g = (color >> 8) & 0xFF;
			b = color & 0xFF;
			if (m == 1)
			{
				r = (r / 64) * 64;
				g = (g / 64) * 64;
				b = (b / 64) * 64;
			}
			printf("\033[48;2;%d;%d;%dm     \033[0m", r, g, b);
			return ;
		}
		i++;
	}
}
// ((color >> 16) & 0xFF), ((color >> 8) & 0xFF), (color & 0xFF))

int	*infosize(char *file)
{
	char	*str;
	int		fd;
	int		i;
	int		*sizeinfo;
	int		j;

	i = 0;
	j = 0;
	fd = -1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	sizeinfo = ft_calloc(3+1 ,sizeof(int));
	if (!sizeinfo)
		return (0);
	while (1)
	{
		str = get_next_line(fd);
		if (i++ == 3)
			break;
		free(str);
	}
	i = 0;
	while (i < 3)
	{
		while (!ft_isdigit((int)str[j]))
			j++;
		sizeinfo[i] = ft_atoi(&str[j]);
		while (ft_isdigit(str[j]))
			j++;
		i++;
	}
	free(str);
	close(fd);
	return (sizeinfo);
}
int		getpicbuff(char ***tab, int fd)
{
	int	i;

	i = 0;
	while (1)
	{
		(*tab)[i] = get_next_line(fd);
		if ((*tab)[i] == NULL)
			return (-1);
		i++;
	}
	return (1);
}

char	**getimg(int *size, int fd)
{
	char	**tab;
	char	*str;

	str = NULL;
	tab = ft_calloc(size[0]+2 ,sizeof(char *));
	if (!tab)
		return (NULL);
	ft_bzero(tab, 2+size[0]);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		if (ft_strncmp(str, "/* pixels */", 11) != 0)
			break;
		free(str);
	}
	free(str);
	getpicbuff(&tab, fd);
	close(fd);
	return (tab); 
}

int		render(char **colors, char *file, int *size)
{
	int		i;
	int		j;
	int		fd;
	char	**tab;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	tab = getimg(size, fd);
	i = 0;
	while (tab[i] != NULL)
	{
		j = 1;
		while (j < size[0] && tab[i][j] && tab[i][j+1])
		{
			if (j+1 < size[0] && tab[i][j] && tab[i][j+1])
				colortohex(colors, tab[i][j], tab[i][j+1], 1);
			j = j + 2;
		}
		printf("\n");
		free(tab[i]);
		i = i + 1;
	}
	free(tab);
	return (1);
}

int	mainrenderer(char *file)
{
	char 	**colors;
	int		*size;

	colors = NULL;
	size = infosize(file);
	colors = get_colors_xpm(file, size);
	if (colors == NULL)
		return (-1);
	// colortohex(colors);
	render(colors, file, size);
	free(size);
	char **temp = colors;
	while (*colors != NULL)
		free(*colors++);
	free(temp);
	return (1);
}

int main(int argc, char **argv)
{

	if (argc != 2)
		return (-1);
	
	if (mainrenderer(argv[1]) == -1)
		return (perror("error"), 0);
	// printf("\n%s displayed\n\n", argv[1]);
	return (0);
}