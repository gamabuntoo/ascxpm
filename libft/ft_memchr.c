/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:55:22 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/19 18:04:29 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*st;

	st = (unsigned char *)s;
	while (n--)
	{
		if (*st == (unsigned char)c)
			return ((void *)st);
		st++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	int c = 'r';
	printf("%s\n", (char *)ft_memchr((const void *) s, c, ft_strlen(s)));
	printf("%s\n", (char *)ft_memchr(s, 0, 0));
	printf("%s\n", (char *)ft_memchr(s, 0, 1));
	printf("%s\n", (char *)ft_memchr(s, 2, 3));
	printf("%s\n", (char *)ft_memchr(s, 6, 6));
	printf("%s\n", (char *)ft_memchr(s, 2 + 256, 3));

	return (0);
}*/
