/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:19:41 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/28 12:14:46 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	m;

	i = 0;
	m = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			return (m);
		while (s[i] && s[i] != c)
			i++;
		m++;
	}
	return (m);
}

static char	*ft_fill(char *dest, char const *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

static char	**ft_alloc(char **str, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	ct;

	i = 0;
	ct = 0;
	while (s[i] && i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && i < ft_strlen(s))
		{
			j = 0;
			while (s[j + i] != c && s[i + j] != '\0')
				j++;
			str[ct] = malloc ((j + 1) * sizeof(char));
			if (!str[ct])
				return (ft_free(str), NULL);
			str[ct] = ft_fill(str[ct], &s[i], j);
			ct++;
			i = j + i;
		}
	}
	return (str);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	x;
	char			**str;

	x = (unsigned int)ft_count_word((char *)s, c);
	str = malloc ((x + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str[x] = NULL;
	str = ft_alloc(str, s, c);
	return (str);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main()
{
	//	const char	s[] = "      split       this for   me  !      ";
	//	char	c = ' ';
	//	char	**split;
	//	split = ft_split(s, c);
	//	while (split[i])
	//	{
	//		printf("%s\n %d\n", split[i], i);
	//		if (i == 4 && split[i+1] == NULL)
	//			printf("SUCCESS");
	//		i++;
	//	}/
	//	ft_free(split);
	const char str[] = "\0aa\0bbb";
	char d ='\0';
	char **sp;
	sp = ft_split("", d);
	printf("%s\n", sp[0]);
	ft_free(sp);
	//	char **strn = ft_split("   test   // twwjir qqq  qqq", ' ');
	//int	i = 0;
	//	while (sp[i] != NULL)
	//	{
	//		printf("%s\n", sp[i]);
	//		i++;
	//	}
	//	ft_free(strn);
	return (0);
}
*/
