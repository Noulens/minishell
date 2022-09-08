/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:44:18 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/08 16:42:44 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		copy_alias2(char *new_str, char *env)
{
	int		i;
	int		j;
	j = ft_strlen(new_str);
	i = 0;
	while (env[i] != 0)
	{
		if (env[i] == '=')
			break;
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

int	break_point_alias(char *str, int i, int trigg)
{
	(void)trigg;
	while (str[i] != 0 && char_is_whitespace(str[i]) != 1  && char_is_token(str[i]) != 1 && char_is_quote(str[i]) != 0)
	{
		i++;
	}
	return (i);
}

int		copy_alias(char *str, char *new_str, char **env, int trigg)
{
	int	j;
	int	k;
	int	i;

	
	j = ft_strlen(new_str);
	k = 0;
	i = 0;
	k = break_point_alias(str, k, trigg);
	while(env[i] != NULL)
	{
			if (ft_strncmp(env[i], str, k) == 0)
			{
				j = copy_alias2(new_str, env[i]);
			}
		i++;
	}
	return (j);
}

char	*init_parsing_alias(char *str, char **env, int len)
{
	char	*new_str;
	int		i;
	int		j;
	int		trigg;

	trigg = 0;
	i = 0;
	j = 0;
	new_str = calloc(sizeof(char), (ft_strlen(str) + len + 1));
	while (str[i] != 0)
	{
		if (str[i] == 39 && check_quote(str, i) == 0 && trigg == 0)
		{
			new_str[j] = str[i];
			j++;
			i++;
			while (str[i] != 39)
			{
				new_str[j] = str[i];
				j++;
				i++;
			}	
		}
		if (str[i] == 34)
		{
			if (trigg == 0)
			trigg = 1;
			else if (trigg == 1)
			trigg = 0;
		}	
		if (str[i] == '$')
		{
			j = copy_alias(str + (i + 1), new_str, env, trigg);
			i = break_point_alias(str, (i + 1), trigg);
			continue ;
		}
		new_str[j] = str[i];
		j++;
		i++;
	}
	return (new_str);
}

int		alias_len(char *str, char **env, int trigg)
{
	int		i;
	int		len;
	int		j;
	
	len = 0;
	j = 0;
	j = break_point_alias(str, j, trigg);
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


char	*parsing_alias(char *str, char **env)
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
		if (str[i] == 34)
		{
			if (trigg == 0)
			trigg = 1;
			else if (trigg == 1)
			trigg = 0;
		}	
		if (str[i] == '$')
			len = (len + alias_len(str + (i + 1), env, trigg));
		i++;
	}
	new_str = init_parsing_alias(str, env, len);
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