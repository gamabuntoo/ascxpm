/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:09:39 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/19 15:33:37 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	ne;
	int	res;

	i = 0;
	ne = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			ne = -ne;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * ne);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("%d\n", ft_atoi(argv[1]));
}*/
