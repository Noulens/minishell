/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_alias.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:44:18 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/12 14:37:21 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	break_point_alias(char *str, int i)
{
	while (str[i] != 0 && char_is_whitespace(str[i]) != 1
		&& char_is_token(str[i]) != 1 && char_is_quote(str[i]) != 0)
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

char	*expend_alias(char *str, char **env, t_minishell *minishell)
{
	char	*new_str;
	int		i;
	int		len;
	int		trigg;

	len = 0;
	i = 0;
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
				len = (len + alias_ret_len(minishell, &i));
			else	
				len = (len + alias_len(str + (i + 1), env));
		}	
		i++;
	}
	new_str = init_str_alias(str, env, len, minishell);
	if (new_str == NULL)
		return (NULL);
	return (new_str);
}

/*
on part du $ et on va jusqu'a un espace un token ou un double guillemet

Seul le $ coupe l'allocation dans une double quote
cette merde est recursive, elle remplace les dollars par les variables jusqu'a un token
si $ strncp jusqu'a l'espace ou le dollar apres l'espace

les regles c'est tout token desactive dans '', sauf $ dans ""
apres ca se stop lorsqu'on croise un token ou un espace

regle de l'export avant
tout ce qui se trouve entre export et le mot precedant (hors token) = n'est pas pris en compte
les quotes ne sont pas pris en compte, pas d'espace a l'interieur et pas de token sinon l'export fail

*/