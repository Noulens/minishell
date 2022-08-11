/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:02:01 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/13 12:55:41 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_writenbrupper(unsigned long int nb, int *len)
{
	char	a;

	if (nb < 10)
		a = nb + 48;
	if (nb >= 10)
		a = nb + 55;
	write(1, &a, 1);
	(*len)++;
}

void	ft_putnbrhexupper(unsigned int nb, int *len)
{
	if (nb >= 16)
	{
		ft_putnbrhexupper(nb / 16, len);
		ft_putnbrhexupper(nb % 16, len);
	}
	if (nb < 16)
		ft_writenbrupper(nb, len);
}

void	ft_putnbrhex_printf(unsigned long int nb, int *len)
{
	if (nb >= 16)
	{
		ft_putnbrhex_printf(nb / 16, len);
		ft_putnbrhex_printf(nb % 16, len);
	}
	if (nb < 16)
		ft_writenbr(nb, len);
}

void	ft_pointerisnullornot(unsigned long nb, int *len)
{
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
	}	
	else
	{
		write(1, "0x", 2);
		ft_putnbrhex_printf(nb, len);
		(*len) += 2;
	}
}
