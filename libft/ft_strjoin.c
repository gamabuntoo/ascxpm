/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:07:20 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/25 15:53:51 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_cp(char *cp, char *src, char *src2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		cp[i] = src[i];
		i++;
	}
	while (src2[j] != '\0')
	{
		cp[i] = src2[j];
		i++;
		j++;
	}
	cp[i] = '\0';
	return (cp);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*nv;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!s1)
	{
		if (!s2)
			return (NULL);
		return ((char *)s1);
	}
	if (!s2)
	{
		if (!s1)
			return (NULL);
		return ((char *)s2);
	}
	nv = (char *)malloc((i + j) + 1 * sizeof(char));
	if (!nv)
		return (NULL);
	nv = ft_cp(nv, (char *)s1, (char *)s2);
	return (nv);
}
/*
#include <stdio.h>

int	main(void)
{
	const char s1[] = "test ";
	const char s2[] = "chaine de caracteres suffixe";
	char *s3 = ft_strjoin(s1, s2);
	printf("%s\n", s3);
	return (0);
}*/
