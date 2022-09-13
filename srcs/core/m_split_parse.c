/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_split_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:58:18 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/12 23:52:22 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_sep_quote(t_mega_split *split, char *s)
{
	if (s[(*split).i] == 34)
	{
		(*split).i++;
		while (s[(*split).i] != 0 && s[(*split).i] != 34)
			(*split).i++;
	}
	else if (s[(*split).i] == 39)
	{
		(*split).i++;
		while (s[(*split).i] != 0 && s[(*split).i] != 39)
			(*split).i++;
	}
}

int	m_split_count_line(char *s, char c)
{
	t_mega_split	split;

	split.count = 1;
	split.i = 0;
	while (s[split.i] != 0)
	{
		if (s[split.i] == c)
			split.count++;
		if (s[split.i] != 0 && char_is_quote(s[split.i]) == 0
			&&parsing_quote(s + split.i) == 0)
			count_sep_quote(&split, s);
		split.i++;
	}
	return (split.count);
}

int	check_empty_str(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (char_is_whitespace(str[i]) == 1)
			j++;
		i++;
	}
	if (i == j)
		return (1);
	return (0);
}

char	**m_split_space_and_quote(char *s, char c)
{
	t_split	split;
	int		i;
	int		j;

	split.str = NULL;
	split.count = 0;
	i = 0;
	j = 0;
	split.len = 0;
	split.count = (m_split_count_line(s, c));
	split.str = (char **)malloc(sizeof(char *) * split.count + sizeof(char *));
	if (split.str == NULL)
		return (NULL);
	while (i < split.count)
	{
		split.str[i] = calloc(sizeof(char), (ft_strlen(s) + 1));
		split.str[i] = m_init_str(s, c, split.str[i], &j);
		if (check_empty_str(split.str[i]) == 1)
			return (ft_printf("synthax error near unexpected token\n"), NULL);
		i++;
	}
	split.str[i] = NULL;
	return (split.str);
}

char	**m_split(char *str)
{
	char	**final_split;

	final_split = m_split_space_and_quote(str, '|');
	return (final_split);
}
