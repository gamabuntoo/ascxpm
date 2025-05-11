/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:09:54 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/19 12:17:40 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*x;
	unsigned char	*y;
	size_t			i;
	size_t			j;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	j = 0;
	x = (void *)src;
	y = dest;
	while (n--)
	{
		y[i++] = x[j++];
	}
	return (dest);
}
/*
#include <stdlib.h>

int	main(void)
{
//	char dest[] = NULL;
//	char src[] = NULL;
	size_t n = 3;
	printf("%s", (unsigned char *)ft_memcpy((void *)NULL, (const void *)NULL, n));
}*/
