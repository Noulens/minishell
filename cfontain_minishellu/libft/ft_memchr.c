/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:04:50 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/11 09:53:38 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*p;
	unsigned char		d;
	size_t				i;

	d = c;
	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == d)
		{
			return ((unsigned char *)s + i);
		}
		i++;
	}
	return (NULL);
}
