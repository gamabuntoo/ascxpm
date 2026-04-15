/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:37:54 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/20 12:22:06 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (((s1[i] == s2[j])
			&& (s1[i] != '\0' || s2[i] != '\0')) && i < n - 1)
	{
		i++;
		j++;
	}
	if (((unsigned char)s1[i] - (unsigned char)s2[j]) > 0)
		return (1);
	if (((unsigned char)s1[i] - (unsigned char)s2[j]) == 0)
		return (0);
	if (((unsigned char)s1[i] - (unsigned char)s2[j]) < 0)
		return (-1);
	return (i);
}
/*
#include <stdio.h>

int	main()
{
	const char s1[] = "abcdefgh";
	const char s2[] = "abcdwxyz";
	size_t n = 4;
	printf("%d\n", (int)ft_strncmp(s1, s2, n));
}*/
