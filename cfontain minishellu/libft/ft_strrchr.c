/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:31:08 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/13 15:37:12 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	d;

	d = c;
	i = 0;
	if (ft_strlen(s) > 0)
		i = (ft_strlen(s) - 1);
	while (i >= 0)
	{
		if (s[i] == d)
		{
			return ((char *)s + i);
		}
		i--;
	}
	if (c == 0)
	{
		return ((char *)s + ft_strlen(s));
	}
	return (NULL);
}
/*

int main()
{
	
	char s[] = "tripouille";
	printf("%s\n", ft_strrchr(s, 't'));
	//printf ("%s\n",ft_strrchr(s, 't' + 256));
}*/