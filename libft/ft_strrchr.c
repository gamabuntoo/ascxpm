/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:21:55 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/19 17:14:33 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	a = 0;
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
			j++;
		}
		i++;
	}
	if (j)
		return (a);
	return (0);
}
/*
int	main()
{
//	const char s[] = "test traquenard train taboule tisane thym";
//	int	c = 'z';
	printf("%s\n", ft_strrchr("teste", '\0'));
}*/
