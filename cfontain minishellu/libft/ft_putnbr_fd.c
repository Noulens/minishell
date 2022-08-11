/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:27:35 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/13 15:48:21 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd1(long n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < 10)
	{
		n = n + 48;
		write(fd, &n, 1);
	}		
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	m;

	m = n;
	ft_putnbr_fd1(m, fd);
}

/*
#include <limits.h>

int main()
{
	ft_putnbr_fd(INT_MIN, 1);
	ft_putnbr_fd(INT_MAX, 1);
}*/