/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_alias.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:44:18 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/16 10:33:43 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	break_point_alias(char *str, int i)
{
	while (str[i] != 0 && char_is_whitespace(str[i]) != 1
		&& char_is_token(str[i]) != 1
		&& char_is_quote(str[i]) != 0 && str[i] != '$')
	{
		i++;
	}
	return (i);
}

int	trigger_double_quote(int trigg, char c)
{
	if (c == 34)
	{
		if (trigg == 0)
			trigg = 1;
		else if (trigg == 1)
			trigg = 0;
	}
	return (trigg);
}

int	alias_ret_len(t_minishell *minishell, int *i)
{
	char	*temp;
	int		value;

	(*i)++;
	temp = NULL;
	temp = ft_itoa(minishell->exec_ret);
	if (temp == NULL)
		return (perror("malloc"), (-1));
	value = ft_strlen(temp);
	free (temp);
	return (value);
}

int	alias_len(char *str, char **env)
{
	int	i;
	int	len;
	int	j;

	len = 0;
	j = 0;
	j = break_point_alias(str, j);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], str, j) == 0)
			len = ft_strlen(env[i]);
		i++;
	}
	if (len == 0)
		return (0);
	return (len - (j + 1));
}

int	expend_alias2(char *str, int i, int len, t_minishell *ms)
{
	int		trigg;

	trigg = 0;
	while (str[i] != 0)
	{
		if (str[i] == 39 && check_quote(str, i) == 0 && trigg == 0)
		{
			i++;
			while (str[i] != 39)
				i++;
		}
		trigg = trigger_double_quote(trigg, str[i]);
		if (str[i] == '$')
		{
			if (str[i + 1] == '?')
				len = (len + alias_ret_len(ms, &i));
			else
				len = (len + alias_len(str + (i + 1), ms->env_array));
		}	
		i++;
	}
	return (len);
}

char	*expend_alias(char *str, t_minishell *ms)
{
	char	*new_str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	len = expend_alias2(str, i, len, ms);
	new_str = init_str_alias(str, len, ms);
	if (new_str == NULL)
		return (NULL);
	return (new_str);
}
