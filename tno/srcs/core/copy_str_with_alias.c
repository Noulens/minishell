/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str_with_alias.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:22:08 by cfontain          #+#    #+#             */
/*   Updated: 2022/10/03 14:44:08 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*init_str_alias(char *str, int len, t_minishell *minishell)
{
	char	*new_str;

	new_str = NULL;
	new_str = calloc(sizeof(char), (len + 1));
	if (new_str == NULL)
		return (perror("malloc"), NULL);
	minishell->i.i = 0;
	minishell->i.j = 0;
	minishell->i.k = 0;
	copy_expend(str, new_str, minishell);
	return (new_str);
}

int	copy_ret(char *new_s, t_minishell *ms)
{
	int		i;
	char	*temp;

	i = 0;
	ms->i.i++;
	temp = NULL;
	temp = ft_itoa(ms->exec_ret);
	if (temp == NULL)
		return (perror("malloc"), (1));
	while (temp[i] != 0)
	{
		new_s[ms->i.j] = temp[i];
		i++;
		ms->i.j++;
	}
	free (temp);
	return (0);
}	

void	copy_alias(char *env, char *new_s, t_minishell *ms)
{
	int	i;

	i = 0;
	while (env[i] != 0)
	{
		if (env[i] == '=')
			break ;
		i++;
	}
	i++;
	while (env[i] != 0)
	{
		new_s[ms->i.j] = env[i];
		i++;
		ms->i.j++;
	}
}

void	search_alias(char *str, char *new_s, t_minishell *ms)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	j = break_point_alias(str, ms->i.i) - ms->i.i;
	while (ms->env_array[k] != NULL)
	{
		if (ft_strncmp(ms->env_array[k], str + ms->i.i, j) == 0
			&& ms->env_array[k][j] == '=')
			copy_alias(ms->env_array[k], new_s, ms);
		k++;
	}
	ms->i.i += (j);
}

int	copy_dollar(char *s, char *new_s, t_minishell *ms)
{
	ms->i.i++;
	if (s[ms->i.i] == '?')
	{
		if (copy_ret(new_s, ms) == 1)
			return (1);
	}	
	else if (char_is_whitespace(s[ms->i.i]) != 1
		&& char_is_token(s[ms->i.i]) != 1 && char_is_quote(s[ms->i.i]) != 0)
		search_alias(s, new_s, ms);
	return (0);
}

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
		if (s[ms->i.i] == '$' && trigger == 0 && s[ms->i.i + 1] != 0 && char_is_token(s[ms->i.i + 1]) == 0)
		{
			if (copy_dollar(s, new_s, ms) == 1)
				return (NULL);
			if (ms->i.i == -1)
				return (NULL);
			continue ;
		}
		trigger = trigg_alias(s, ms, trigger);
		copy_str(s, new_s, ms);
	}
	return (new_s);
}	
