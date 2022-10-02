/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str_with_alias.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:22:08 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/27 17:47:39 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int	copy_alias2(char *new_str, char *env)
{
	int	i;
	int	j;

	j = ft_strlen(new_str);
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
		new_str[j] = env[i];
		i++;
		j++;
	}
	return (j);
}

int	copy_alias(char *str, char *new_str, t_minishell *ms)
{
	int	j;
	int	k;
	int	i;

	j = ft_strlen(new_str);
	k = 0;
	i = 0;
	k = break_point_alias(str, k);
	while (ms->env_array[i] != NULL)
	{
		if (ft_strncmp(ms->env_array[i], str, k) == 0)
		{
			if (ms->env_array[i][k] == '=')
				j = copy_alias2(new_str, ms->env_array[i]);
		}	
		i++;
	}
	return (j);
}

int	alias_copy_with_single_quote(char *str, char *new_str, int *i, int j)
{
	new_str[j] = str[(*i)];
	j++;
	(*i)++;
	while (str[(*i)] != 39)
	{
		new_str[j] = str[(*i)];
		j++;
		(*i)++;
	}
	return (j);
}

int	alias_ret(char *new_str, t_minishell *minishell)
{
	char	*temp;
	int		value;

	value = 0;
	temp = NULL;
	temp = ft_itoa(minishell->exec_ret);
	if (temp == NULL)
		return (perror("malloc"), 1);
	ft_strlcat(new_str, temp, (ft_strlen(new_str) + ft_strlen(temp) + 1));
	value = ft_strlen(new_str);
	free (temp);
	if (value == 0)
		return (0);
	return ((value));
}

void	copy_str(char *str, char *new_str, t_minishell *ms)
{
	new_str[ms->i.j] = str[ms->i.i];
	ms->i.j++;
	ms->i.i++;
}

void	test(char *str, char *new_str, t_minishell *ms)
{
	if (str[ms->i.i] == 39 && check_quote(str, ms->i.i) == 0 && ms->i.k == 0)
	{
		ms->i.j = alias_copy_with_single_quote(str, new_str, &ms->i.i, ms->i.j);
		ms->i.k = trigger_double_quote(ms->i.k, str[ms->i.i]);
	}	
}

void	init_copy_alias(char *new_str, char *str, t_minishell *ms)
{
	while (str[ms->i.i] != 0)
	{
		test(str, new_str, ms);
		if (str[ms->i.i] == '$')
		{
			if (str[ms->i.i + 1] == '?')
			{
				ms->i.j = alias_ret(new_str, ms);
				ms->i.i += 2;
				continue ;
			}
			else if (char_is_token(str[ms->i.i + 1]) == 0 && str[ms->i.i + 1]
				!= '$' && str[ms->i.i + 1] != 0
				&& char_is_whitespace(str[ms->i.i + 1]) == 0
				&& char_is_quote(str[ms->i.i + 1]) == 1)
			{	
				ms->i.j = copy_alias(str + (ms->i.i + 1), new_str, ms);
				ms->i.i = break_point_alias(str, (ms->i.i + 1));
				continue ;
			}	
		}
		copy_str(str, new_str, ms);
	}
}
*/
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

/*int	break_point_alias(char *str, int i)
{
	while (str[i] != 0 && char_is_whitespace(str[i]) != 1
		&& char_is_token(str[i]) != 1
		&& char_is_quote(str[i]) != 0 && str[i] != '$')
	{	
		i++;
	}	
	return (i);
}*/

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
		if (s[ms->i.i] == '$' && trigger == 0)
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
