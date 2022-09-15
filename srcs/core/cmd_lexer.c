/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:53:51 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/15 16:53:25 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_lexer_leght(char *str, int i)
{
	int		trigger;
	char	c;

	c = 0;
	trigger = 0;
	while (str[i] != 0 && char_is_token_with_trigg(str[i], trigger) == 0)
	{
		if (char_is_quote(str[i]) == 0
			&& check_quote(str, i) == 0 && trigger == 0)
		{
			trigger = 1;
			c = str[i];
			i++;
			continue ;
		}
		if (c == str[i])
			trigger = 0;
		i++;
	}
	return (i);
}

int	cmd_lexer(char *str, int i, t_minishell *minishell)
{
	char	*new_str;
	int		j;

	j = i;
	i = cmd_lexer_leght(str, i);
	new_str = calloc(sizeof(char), (i + 1));
	if (new_str == NULL)
		return (-1);
	ft_strlcpy(new_str, str + j, ((i - j) + 1));
	ft_lstadd_back_tok(&minishell->list, ft_lstnew_tok(new_str, CMD_LEX));
	return (i);
}
