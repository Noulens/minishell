/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_expender.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:22:08 by cfontain          #+#    #+#             */
/*   Updated: 2022/10/06 15:16:51 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_str(char *str, char *new_str, t_minishell *ms)
{
	new_str[ms->i.j] = str[ms->i.i];
	ms->i.j++;
	ms->i.i++;
}

int	trigg_alias(char *s, t_minishell *ms, int trigger)
{
	int	trigger2;
	int	i;

	i = ms->i.i;
	trigger2 = ms->i.k;
	if (s[i] == 34 && trigger2 == 0)
		trigger2 = 1;
	else if (s[i] == 34 && trigger2 == 1)
		trigger2 = 0;
	if (s[i] == 39 && trigger == 0 && check_quote(s, i) == 0 && trigger2 == 0)
		trigger = 1;
	else if (s[i] == 39 && trigger == 1)
		trigger = 0;
	ms->i.k = trigger2;
	return (trigger);
}

char	*copy_expend(char *s, char *new_s, t_minishell *ms)
{
	int		trigger;

	trigger = 0;
	while (s[ms->i.i] != 0)
	{
		if (s[ms->i.i + 1] == '?' || (s[ms->i.i] == '$'
				&& trigger == 0 && ft_isalnum(s[ms->i.i + 1]) == 1))
		{
			if (copy_dollar(s, new_s, ms) == 1)
				return (NULL);
			continue ;
		}
		trigger = trigg_alias(s, ms, trigger);
		copy_str(s, new_s, ms);
	}
	return (new_s);
}	

char	*init_expender(char *str, int len, t_minishell *minishell)
{
	char	*new_str;

	new_str = NULL;
	new_str = calloc(sizeof(char), (len + 1));
	if (new_str == NULL)
		return (perror("malloc"), NULL);
	minishell->i.i = 0;
	minishell->i.j = 0;
	minishell->i.k = 0;
	if (copy_expend(str, new_str, minishell) == NULL)
		return (free (new_str), NULL);
	return (new_str);
}
