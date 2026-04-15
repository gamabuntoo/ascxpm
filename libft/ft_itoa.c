/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:10:27 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/28 14:22:20 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h" 

static int	decimals(long long int n)
{
	unsigned int	x;

	x = 0;
	while (n)
	{
		n /= 10;
		x++;
	}
	return (x);
}

static void	ft_content(long long value, int index, char *str, int min)
{
	int	x;

	x = index;
	if (min == 0)
	{
		str[x] = '\0';
		x -= 1;
	}
	while (x > 0)
	{
		str[x] = (value % 10) + '0';
		value /= 10;
		x--;
	}
	str[x] = (value % 10) + '0';
	if (min == 1)
	{
		str[0] = '-';
		str[index + 1] = '\0';
	}
}

char	*ft_itoa(int n)
{
	int				x;
	int				y;
	long long int	nb;
	char			*res;

	nb = n;
	y = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		y = 1;
		nb = -nb;
		x = decimals(nb);
		res = malloc((x + 2) * sizeof(char));
	}
	else
	{
		x = decimals(nb);
		res = malloc((x + 1) * sizeof(char));
	}
	if (!res)
		return (NULL);
	return (ft_content(nb, x, res, y), res);
}
/*
#include <stdio.h>

int	main()
{
	int	n = -25;
	char *test = ft_itoa(n);
	printf("%s\n", test);
	int i = 0;
	while (test[i] != '\0')
	{
		ft_putchar_fd(test[i], 1);
		i++;
	}
	free(test);
	printf("\n");
	int	m = 214;
	char *test1 = ft_itoa(m);
	printf("%s\n", test1);
	free(test1);
	int	z = 0;
	char *testz = ft_itoa(z);
	printf("%s\n", testz);
	i = 0;
	while (testz[i] != '\0')
	{
		ft_putchar_fd(testz[i], 1);
		i++;
	}
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(8));
	printf("%s\n", ft_itoa(2147483647));
	return (0);
}*/
