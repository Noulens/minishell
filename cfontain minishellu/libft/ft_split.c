/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:06:28 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/05 11:31:47 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countstr(char const *s, char c)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	j = 0;
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] != 0 && s[i] == c)
		{
			i++;
		}	
		while (s[i] != 0 && s[i] != c)
		{	
			i++;
			j++;
		}
		if (j > 0)
		{	
			count++;
			j = 0;
		}
	}
	return (count);
}

static char	*ft_initstr2(char *str, int len)
{
	str = (char *)malloc(sizeof(char) * (len) + sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_memset(str, 0, len + 1);
	return (str);
}

static char	*ft_initstr(char const *s, char c, char *str, int *j)
{
	int		i;
	int		k;

	k = 0;
	i = *j;
	while (s[i] != 0 && s[i] == c)
	{
		i++;
	}
	while (s[i] != 0 && s[i] != c)
	{
		str[k] = s[i];
		i++;
		k++;
	}
	*j = i;
	return (str);
}

static int	ft_strlenght(char const *s, char c, int *j)
{
	int		i;
	int		k;

	k = 0;
	i = *j;
	while (s[i] != 0 && s[i] == c)
	{
		i++;
	}
	while (s[i] != 0 && s[i] != c)
	{
		i++;
		k++;
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	t_split	split;
	int		i;
	int		j;

	split.str = NULL;
	split.count = 0;
	i = 0;
	j = 0;
	split.len = 0;
	split.count = (ft_countstr(s, c));
	split.str = (char **)malloc(sizeof(char *) * (split.count + 1));
	if (split.str == NULL)
		return (NULL);
	while (i < split.count)
	{
		split.str[i] = 0;
		split.len = ft_strlenght(s, c, &j);
		split.str[i] = ft_initstr2(split.str[i], split.len);
		if (split.str[i] == NULL)
			return (destroy_str(split.str), NULL);
		split.str[i] = ft_initstr(s, c, split.str[i], &j);
		i++;
	}
	split.str[i] = 0;
	return (split.str);
}

/*
void freeTab(char * * tab)
{
	for (int i = 0; tab[i] != NULL; ++i)
		free(tab[i]);
	free(tab);
}

int main(void)
{
		char * * tab = ft_split("  tripouille  42  ", ' ');
		printf("%s\n", tab[0]);

		printf("%ld\n", ft_strlen(tab[0]));
		freeTab(tab);
				
}*/