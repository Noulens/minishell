/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str_with_alias.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:22:08 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/15 16:28:34 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*init_str_alias(char *str, int len, t_minishell *minishell)
{
	char	*new_str;

	new_str = NULL;
	new_str = calloc(sizeof(char), (ft_strlen(str) + len + 1));
	if (new_str == NULL)
		return (perror("malloc"), NULL);
	minishell->i.i = 0;
	minishell->i.j = 0;
	minishell->i.k = 0;
	init_copy_alias(new_str, str, minishell);
	return (new_str);
}
