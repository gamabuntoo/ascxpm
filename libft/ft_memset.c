/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:35:52 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/12 16:54:53 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = s;
	while (n)
	{
		str[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (s);
}
/*
int	ft_atoi(char *a)
{
	int	res;
	int	v;
	res = 0;
	v = 0;
	while (a[v] != '\0')
	{
		res *= 10;
		res += a[v] - '0';
		v++;
	}
	return (res);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	char *str = ft_memset((void *)argv[1], '0', ft_atoi(argv[2]));
	printf("%s", str);
}*/
