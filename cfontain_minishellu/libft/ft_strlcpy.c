/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:26:24 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/10 15:08:00 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	j = ft_strlen(src);
	if (!src || !dest)
		return (0);
	if (size <= 0)
	{
		return (j);
	}	
	while (src[i] != 0 && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (j);
}	

/*

int main()
{
	char src[] = "coucou";
	char dest[10]; memset(dest, 'A', 10);
	//ft_strlcpy(dest, src, 2);
	printf("%ld\n", ft_strlcpy(dest, src, 2));
	printf("%s\n", dest);
	printf("%c\n", dest[1]);
	printf("%c\n", dest[2]);
	// == strlen(src) && dest[0] == 'c' && dest[1] == 0  && dest[2] == 'A')
}*/