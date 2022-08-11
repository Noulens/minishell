/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:31:08 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/11 09:40:24 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	d;

	d = c;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == d)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
