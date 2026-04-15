/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:30:46 by gule-bat          #+#    #+#             */
/*   Updated: 2024/11/28 11:31:29 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_fd(int nb, int fd)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
/*
int	main(void)
{
	int	n = 2147483647;
	int	f = -2147483648;
	ft_putnbr_fd(n, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(f, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(1, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-22458LL, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-22458LL, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(n, 2);
	ft_putchar_fd('\n', 1);
	usleep(500000);
	ft_putnbr_fd(f, 2);
	ft_putchar_fd('\n', 1);
	usleep(500000);
	ft_putnbr_fd(0, 2);
	ft_putchar_fd('\n', 1);
	usleep(500000);
	ft_putnbr_fd(1, 2);
	ft_putchar_fd('\n', 1);
	usleep(500000);
	ft_putnbr_fd(-42, 2);
	ft_putchar_fd('\n', 1);
	usleep(500000);
	ft_putnbr_fd(-22458LL, 2);
	ft_putchar_fd('\n', 1);
	usleep(500000);
	ft_putnbr_fd(-22458LL, 2);
	ft_putchar_fd('\n', 1);
	usleep(500000);
}*/
