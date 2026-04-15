/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:13:53 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/15 16:01:29 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*str;
	size_t	total;

	total = nitems * size;
	str = malloc(total);
	if (!str)
		return (NULL);
	ft_bzero(str, total);
	return (str);
}
