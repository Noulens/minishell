/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:59:29 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/13 12:55:43 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_printf(int a, int *len)
{
	char	b;

	b = a;
	write(1, &b, 1);
	(*len)++;
}

void	ft_putstr_printf(char *str, int *len)
{
	int		i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
	}	
	if (str)
	{
		while (str[i] != 0)
		{
			write(1, &str[i], 1);
			i++;
			(*len)++;
		}
	}
}

void	ft_writenbr(unsigned long int nb, int *len)
{
	char	a;

	if (nb < 10)
		a = nb + 48;
	if (nb >= 10)
		a = nb + 87;
	write(1, &a, 1);
	(*len)++;
}

void	ft_putnegative(int *len)
{
	write(1, "-", 1);
	(*len)++;
}	

void	ft_putnbr_printf(long int nb, int *len)
{
	if (nb < 0)
	{
		ft_putnegative(len);
		nb = nb * (-1);
	}	
	if (nb >= 10)
	{
		ft_putnbr_printf(nb / 10, len);
		ft_putnbr_printf(nb % 10, len);
	}
	if (nb < 10)
		ft_writenbr(nb, len);
}
