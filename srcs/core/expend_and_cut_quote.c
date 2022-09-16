/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_and_cut_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:11:25 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/16 10:35:48 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dup_without_quote(char *str, char *new_str, int i, int j)
{
	char	c;
	int		trigger;

	trigger = 0;
	c = 0;
	while (str[i] != 0)
	{
		if (char_is_quote(str[i]) == 0 && check_quote(str, i) == 0
			&& trigger == 0)
		{
			c = str[i];
			trigger++;
			i++;
		}
		if (str[i] == c)
		{
			i++;
			trigger = 0;
			continue ;
		}	
		new_str[j] = str[i];
		j++;
		i++;
	}
	return (0);
}

char	*dup_without_quote_init(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	new_str = calloc(sizeof(char), (ft_strlen(str) + 1));
	dup_without_quote(str, new_str, i, j);
	return (new_str);
}

int	expend_and_cut_quote(t_minishell *minishell)
{
	char	*str;
	char	*str2;
	t_tok	*temp;

	temp = minishell->list;
	while (minishell->list)
	{
		str = expend_alias(minishell->list->data, minishell);
		free (minishell->list->data);
		str2 = dup_without_quote_init(str);
		free (str);
		minishell->list->data = str2;
		minishell->list = minishell->list->next;
	}
	minishell->list = temp;
	ft_lstadd_back_tok(&minishell->list, ft_lstnew_tok(NULL, END_LEX));
	return (0);
}
