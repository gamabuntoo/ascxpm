/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:21 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/19 15:28:44 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sa;
	unsigned char	*sb;

	if (n == 0)
		return (0);
	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	i = 0;
	while (((sa[i] == sb[i]) && (i < n - 1)))
		i++;
	if ((sa[i] - sb[i]) > 0)
		return (1);
	if ((sa[i] - sb[i]) == 0)
		return (0);
	if ((sa[i] - sb[i]) < 0)
		return (-1);
	return ((int)i);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	if (argc < 2)
		return (0);
	size_t	n = 7;
	printf("%d\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));
	return (0);
}*/
