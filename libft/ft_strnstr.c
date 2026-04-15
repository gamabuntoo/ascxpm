/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:33:42 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/20 15:45:16 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*a;

	i = 0;
	if (len < ft_strlen(little) && (!little))
		return ((char *)big);
	if (little[0] == '\0')
		return ((char *)&big[i]);
	while (big[i] && i < len)
	{
		j = 0;
		a = 0;
		while (big[i + j] == little[j] && ((i + j) < len))
		{
			a = (char *)&big[i];
			j++;
			if (little[j] == '\0')
				return (a);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main()
{
	const char s[] = "test traquenard train taboule tisane thym train";
	const char little[] = "train";
	size_t n = 25;
	printf("%s\n", ft_strnstr(s, little, n));
	printf("%s\n", ft_strnstr("", "", 0));
	printf("%s\n", ft_strnstr("", "", 1));
	printf("%s\n", ft_strnstr("", "", 2));
	printf("%s\n", ft_strnstr("teste", "", 0));
	printf("%s\n", ft_strnstr("teste", "", 1));
	printf("%s\n", ft_strnstr("teste", "", 2));
	printf("%s\n", ft_strnstr(((void*)0), "fake", 3));
}*/
