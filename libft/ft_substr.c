/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:44:37 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/28 12:15:41 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < (unsigned int)len)
	{
		sub[i] = (char)s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return ((char *)sub);
}
/*
#include <stdio.h>

int	main(void)
{
char *str = "01234";
size_t size = 10;
char *ret = ft_substr(str, 10, size);
printf("%s\n", ft_substr("hola", 4294967295, 0));
printf("%s\n", ft_substr("i just want this part #############", 5, 20));
printf("%s\n", ret);
return(0);
}*/
