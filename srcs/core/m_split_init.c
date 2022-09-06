/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_split_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:20:29 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/06 11:51:45 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_count_up(t_mega_split *split)
{
	if ((*split).j > 0)
	{
		(*split).count++;
		(*split).j = 0;
	}
}	

char	*m_init_str(char *s, char c, char *str, int *j)
{
	int		i;
	int		k;

	k = 0;
	i = *j;
	while (s[i] != 0 && s[i] == c)
			i++;
	while (s[i] != 0 && s[i] != c)
	{
		if (char_is_quote(s[i]) == 0)
		{
			if (parsing_quote(s + i) == 0)
			{
				m_init_str_with_sep(s, str, &i, &k);
				return ((*j = i), str);
			}
		}
		str[k] = s[i];
		i++;
		k++;
	}
	return ((*j = i), str);
}

int	m_line_lenght(char *s, char c, int *j)
{
	int		i;
	int		k;

	k = 0;
	i = *j;
	while (s[i] != 0 && s[i] == c)
		i++;
	while (s[i] != 0 && s[i] != c)
	{
		if (s[i] == 34 || s[i] == 39)
		{
			i++;
			k++;
			while (s[i] != 0 && (s[i] != 34 || s[i + 1] != ' ')
				&& (s[i] != 39 || s[i + 1] != ' '))
			{
				i++;
				k++;
			}
			return (k);
		}
		i++;
		k++;
	}
	return (k);
}

char	*m_malloc_str(char *str, int len)
{
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	str = ft_memset(str, 0, len + 2);
	return (str);
}

void	m_init_str_with_sep(char *s, char *str, int *i, int *k)
{
	char	c;

	c = s[(*i)];
	str[(*k)] = s[(*i)];
	(*k)++;
	(*i)++;
	while (s[(*i)] != 0 && s[(*i)] != c)
	{
		str[(*k)] = s[(*i)];
		(*k)++;
		(*i)++;
	}
	while (s[(*i)] != 0 && s[(*i)] != ' ')
	{
		str[(*k)] = s[(*i)];
		(*k)++;
		(*i)++;
	}
}
