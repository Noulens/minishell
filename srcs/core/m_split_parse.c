/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_split_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:58:18 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/05 16:36:45 by tnoulens         ###   ########.fr       */
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
		while (s[(*split).i] != 0 && s[(*split).i] != ' ')
			(*split).i++;
	}
	else if (s[(*split).i] == 39)
	{
		(*split).i++;
		while (s[(*split).i] != 0 && s[(*split).i] != 39)
			(*split).i++;
		while (s[(*split).i] != 0 && s[(*split).i] != ' ')
			(*split).i++;
	}
}

int	char_is_sep(char c)
{
	if (c == 34 || c == 39)
		return (0);
	else
		return (1);
}

int	m_split_count_line(char *s, char c)
{
	t_mega_split	split;

	split.count = 1;
	split.j = 0;
	split.i = 0;
	while (s[split.i] != 0)
	{
		while (s[split.i] && s[split.i] == c)
		{
			split.i++;
			split.j++;
		}
		if (s[split.i] != 0 && char_is_sep(s[split.i]) == 0
			&&parsing_quote(s + split.i) == 0)
			count_sep_quote(&split, s);
		else
			split.i++;
		ft_count_up(&split);	
	}
	if (s[0] == c)
		split.count--;
	if (s[(ft_strlen(s) - 1)] == c)
		split.count--;
	return (split.count);
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
	split.str = (char **)malloc(sizeof(char *) * (split.count + 1));
	if (split.str == NULL)
		return (NULL);
	while (i < split.count)
	{
		split.str[i] = 0;
		split.len = m_line_lenght(s, c, &j);
		split.str[i] = m_malloc_str(split.str[i], split.len);
		if (split.str[i] == NULL)
			return (ft_free_split(split.str), NULL);
		split.str[i] = m_init_str(s, c, split.str[i], &j);
		i++;
	}
	split.str[i] = 0;
	return (split.str);
}

char	**m_split(char *str)
{
	char	**final_split;

	final_split = m_split_space_and_quote(str, ' ');
	return (final_split);
}
