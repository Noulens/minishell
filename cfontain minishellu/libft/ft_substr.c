/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:22:30 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/13 15:41:45 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > start && start != 1)
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
/*
int main()
{

	char * s = ft_substr("tripouille", 0, 42000);
	printf("tripouille = %s\n", s);
	printf("%ld\n", ft_strlen(s));
	s = ft_substr("tripouille", 1, 1);
	printf("r = %s\n", s);
	s = ft_substr("tripouille", 100, 1);
	printf(" = %s\n", s);
	char * str = strdup("1");
	s = ft_substr(str, 42, 42000000);
	printf(" = %s\n", s);
	str = strdup("0123456789");
	s = ft_substr(str, 9, 10);
	printf("9 = %s\n", s);
	s = ft_substr("42", 0, 0);
	printf("  = %s\n", s);
	s = ft_substr("BONJOUR LES HARICOTS !", 8, 14);
	printf("LES HARICOTS ! = %s\n", s);
	s = ft_substr("test", 1, 2);
	printf("es = %s\n", s);
	free (s);

}*/