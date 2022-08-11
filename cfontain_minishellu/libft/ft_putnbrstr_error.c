/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrstr_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:27:52 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/01 12:45:56 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_printf_error(int a, int *len)
{
	char	b;

	b = a;
	write(2, &b, 1);
	(*len)++;
}

void	ft_putstr_printf_error(char *str, int *len)
{
	int		i;

	i = 0;
	if (!str)
	{
		write(2, "(null)", 6);
		(*len) += 6;
	}	
	if (str)
	{
		while (str[i] != 0)
		{
			write(2, &str[i], 1);
			i++;
			(*len)++;
		}
	}
}

void	ft_writenbr_error(unsigned long int nb, int *len)
{
	char	a;

	if (nb < 10)
		a = nb + 48;
	if (nb >= 10)
		a = nb + 87;
	write(2, &a, 1);
	(*len)++;
}

void	ft_putnegative_error(int *len)
{
	write(2, "-", 1);
	(*len)++;
}	

void	ft_putnbr_printf_error(long int nb, int *len)
{
	if (nb < 0)
	{
		ft_putnegative_error(len);
		nb = nb * (-1);
	}	
	if (nb >= 10)
	{
		ft_putnbr_printf_error(nb / 10, len);
		ft_putnbr_printf_error(nb % 10, len);
	}
	if (nb < 10)
		ft_writenbr_error(nb, len);
}
