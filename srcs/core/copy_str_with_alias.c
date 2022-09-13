/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str_with_alias.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:22:08 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/12 14:38:15 by cfontain         ###   ########.fr       */
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

int	copy_alias(char *str, char *new_str, char **env)
{
	int	j;
	int	k;
	int	i;

	j = ft_strlen(new_str);
	k = 0;
	i = 0;
	k = break_point_alias(str, k);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], str, k) == 0)
		{
			if (env[i][k] == '=')
				j = copy_alias2(new_str, env[i]);
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

void	init_copy_alias(char *new_str, char *str, char **env, t_minishell *minishell)
{
	int	i;
	int	j;
	int	trigg;

	trigg = 0;
	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] == 39 && check_quote(str, i) == 0 && trigg == 0)
			j = alias_copy_with_single_quote(str, new_str, &i, j);
		trigg = trigger_double_quote(trigg, str[i]);
		if (str[i] == '$')
		{
			if (str[i + 1] == '?')
			{
				j = alias_ret(new_str, minishell);
				i += 2;
				continue ;
			}
			else if (char_is_token(str[i + 1] == 1) || str[i + 1] == '$' || str[i + 1] == 0 || char_is_whitespace(str[i + 1]) == 1 || char_is_quote(str[i + 1]) == 0)
			{

			}
			else
			{	
				j = copy_alias(str + (i + 1), new_str, env);
				i = break_point_alias(str, (i + 1));
				continue ;
			}	
			
		}
		new_str[j] = str[i];
		j++;
		i++;
	}
}

char	*init_str_alias(char *str, char **env, int len, t_minishell *minishell)
{
	char	*new_str;

	new_str = NULL;
	new_str = calloc(sizeof(char), (ft_strlen(str) + len + 1));
	if (new_str == NULL)
		return (perror("malloc"), NULL);
	init_copy_alias(new_str, str, env, minishell);
	return (new_str);
}
