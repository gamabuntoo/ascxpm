/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:58:17 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/19 17:12:09 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*a;

	i = 0;
	if ((char)c == '\0')
	{
		a = (char *)&s[ft_strlen(s)];
		return (a);
	}
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			a = (char *)&s[i];
			return (a);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	const char s[] = "test bagnole rica \0 rd verre a ballon";
	int c = '\0';
	printf("%s\n", ft_strchr(s, c));
	return (0);
}*/
