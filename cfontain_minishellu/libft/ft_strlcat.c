/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:26:24 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/11 09:47:57 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		lendest;
	int		lensrc;
	size_t	i;
	size_t	j;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	i = 0;
	j = ft_strlen(dest);
	if (size <= j)
		return (size + ft_strlen(src));
	while (src[i] != 0 && j < (size - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = 0;
	if (size < ft_strlen(dest))
		return (lendest + size);
	else
		return (lendest + lensrc);
}
