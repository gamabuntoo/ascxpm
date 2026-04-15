/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:25:00 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/25 15:54:36 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_testset(const char s1, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	a;
	char	*trim;

	i = 0;
	a = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_testset(s1[i], set) == 1)
		i++;
	while (((ft_testset(s1[j - 1], set) == 1)) && j > i)
		j--;
	trim = malloc((j - i + 1) * sizeof(*s1));
	if (!trim)
		return (NULL);
	while (i < j)
	{
		trim[a] = s1[i];
		a++;
		i++;
	}
	trim[a] = '\0';
	return (trim);
}
/*
#include <stdio.h>
int	main()
{
	const char s0[] = "EATEQStest bagnole tartine thymQQQSPSE";
const char set[] = "PASTEQUE";
	char	*stock = ft_strtrim(s1, set);
	int	i = 0;
	char *s1 = "  \t \t \n   \n\n\n\t";
 	char *s2 = "";
 	char *ret = ft_strtrim(s1, " \n\t");
	while(s2[i] == ret[i])
	{
		i++;
		printf("same\n");
	}
	printf("%s\n ok", ret);
	char *s3 = "   \t  \n\n \t\t  \n\n\nHello \t  
	Please\n Trim me !\n   \n \n \t\t\n  ";
 	char *s4 = "Hello \t  Please\n Trim me !";
 	char *reto = ft_strtrim(s3, " \n\t");
	i = 0;
	while (reto[i] == s4[i])
	{
		i++;
		printf("same");
	}
	printf("%s\n", reto);
	printf("\n%s\n", ft_strtrim(" . abcd", " "));
//	printf("%s\n trimmed array\n %s\n trimmed charset", stock, set);
//	free(stock);
}*/
