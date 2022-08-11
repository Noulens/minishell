/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:59:37 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/13 16:11:33 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putstr(char *str, long int n)
{
	int		i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9' ) || str[i] == '-')
	{
		i++;
	}
		str[i] = n + 48;
	return (str);
}

static char	*ft_putnbr(char *str, long int n)
{
	if (n >= 10)
	{
		ft_putnbr(str, (n / 10));
		ft_putnbr(str, (n % 10));
	}
	if (n < 10)
	{
		ft_putstr(str, n);
	}
	return (str);
}

static char	*ft_initstr(int len, long int n)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, len + 1);
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}	
	ft_putnbr(str, n);
	return (str);
}

char	*ft_itoa(int n)
{
	int				len;
	long int		j;
	char			*str;

	j = n;
	len = 1;
	if (n < 0)
		len = 2;
	while ((j / 10) != 0)
	{
		len++;
		j = (j / 10);
	}
	str = ft_initstr(len, n);
	return (str);
}
/*
#include <limits.h>

int main()
{
	printf("%s\n",ft_itoa(INT_MIN));
	printf("%s\n",ft_itoa(452));

	
}*/