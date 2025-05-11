/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:51:07 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/20 12:04:58 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_lengh;
	size_t	src_lengh;
	size_t	i;

	dst_lengh = ft_strlen(dst);
	src_lengh = ft_strlen(src);
	i = 0;
	if (size == 0 || dst_lengh > size)
		return (src_lengh + size);
	if (src == NULL)
		return (dst_lengh);
	while (src[i] && (dst_lengh + i < size -1))
	{
		dst[dst_lengh + i] = src[i];
		i++;
	}
	dst[dst_lengh + i] = '\0';
	return (src_lengh + dst_lengh);
}
/*#include <stdlib.h>
#include <bsd/string.h> 

int	main()
{
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
 	char buff1[0xF00] = "there is no stars in the sky";
 	char buff2[0xF00] = "there is no stars in the sky";
 	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
 
 	printf("%d\n", (int)strlcat(buff1, str, max));
 	printf("%d\n", (int)ft_strlcat(buff2, str, max));
}*/
