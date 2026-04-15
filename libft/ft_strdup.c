/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:27:35 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/16 14:56:51 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int	i;
	int	y;
	char
		*sstr;

	i = 0;
	y = 0;
	while (str[i] != '\0')
		i++;
	sstr = (char *)malloc((i + 1) * sizeof(char));
	if (!sstr)
		return (NULL);
	while (str[y] != '\0')
	{
		sstr[y] = str[y];
		y++;
	}
	sstr[y] = '\0';
	return (sstr);
}
/*
#include <stdio.h>

int	main(void)
{
	const char st[] = "un petit ricard dans un verre a ballons";
	char *s = ft_strdup(st);
	printf("%s\n premiere str\n\n", st);
	printf("%d\n taille originale \n", (int)ft_strlen(st));
	printf("%s\n dup\n", s);
	printf("%d\n taille dup\n", (int)ft_strlen(s));
	return(0);
}*/
