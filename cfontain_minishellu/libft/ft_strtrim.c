/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:09:59 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/12 15:23:32 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checksep(char s1, char const *set)
{
	int		i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == s1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*ft_strinit(char const *s1, int len, int i)
{
	char	*str;
	int		j;

	j = 0;
	str = malloc(sizeof(char ) * (len + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	ft_memset(str, 0, len);
	while (j < len)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(""));
	while (ft_checksep (s1[i], set) == 1)
	{
		i++;
	}
	j = (ft_strlen(s1) - 1);
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	while (j >= 0 && ft_checksep(s1[j], set) == 1)
	{
		j--;
	}
	str = ft_strinit(s1, (j - i) + 1, i);
	return (str);
}
/*
int main()
{
	//char * s = ft_strtrim("   xxxtripouille", " x");
	//s = ft_strtrim("   xxxtripouille   xxx", " x");
	//printf("%s\n", s);
	
	//check(!strcmp(s, "tripouille"));
	//mcheck(s, strlen("tripouille") + 1); free(s); showLeaks();
	
	char * s = ft_strtrim("   xxx   xxx", " x");
	printf("%s\n", s);
	//check(!strcmp(s, ""));
	//mcheck(s, 1); free(s); showLeaks();


}*/
