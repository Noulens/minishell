/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:33:10 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/01 12:45:51 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_writenbrupper_error(unsigned long int nb, int *len)
{
	char	a;

	if (nb < 10)
		a = nb + 48;
	if (nb >= 10)
		a = nb + 55;
	write(2, &a, 1);
	(*len)++;
}

void	ft_putnbrhexupper_error(unsigned int nb, int *len)
{
	if (nb >= 16)
	{
		ft_putnbrhexupper_error(nb / 16, len);
		ft_putnbrhexupper_error(nb % 16, len);
	}
	if (nb < 16)
		ft_writenbrupper_error(nb, len);
}

void	ft_putnbrhex_printf_error(unsigned long int nb, int *len)
{
	if (nb >= 16)
	{
		ft_putnbrhex_printf_error(nb / 16, len);
		ft_putnbrhex_printf_error(nb % 16, len);
	}
	if (nb < 16)
		ft_writenbr_error(nb, len);
}

void	ft_pointerisnullornot_error(unsigned long nb, int *len)
{
	if (nb == 0)
	{
		write(2, "(nil)", 5);
		(*len) += 5;
	}	
	else
	{
		write(2, "0x", 2);
		ft_putnbrhex_printf_error(nb, len);
		(*len) += 2;
	}
}
