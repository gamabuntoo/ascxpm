/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:44:36 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/20 18:59:49 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	c;
	char	*str;

	i = ft_strlen(s);
	c = 0;
	str = malloc(i + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (c < i)
	{
		str[c] = f(c, s[c]);
		c++;
	}
	str[c] = '\0';
	return (str);
}
