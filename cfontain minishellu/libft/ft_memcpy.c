/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:59:18 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/09 12:43:57 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*b;
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = dest;
	b = src;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}	
	return (dest);
}	
