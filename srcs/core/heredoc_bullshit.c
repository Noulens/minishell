/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bullshit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:54:49 by cfontain          #+#    #+#             */
/*   Updated: 2022/10/12 12:26:11 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*suppr_double_quote(char *str)
{
	char	*new_str;

	new_str = ft_calloc(sizeof(char), ft_strlen(str));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, str + 1, (ft_strlen(str) - 1));
	free (str);
	return (new_str);
}

char	*add_double_quote(char *str)
{
	char	*new_str;

	new_str = ft_calloc(sizeof(char), (ft_strlen(str) + 3));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str + 1, str, (ft_strlen(str) + 1));
	new_str[0] = 34;
	new_str[ft_strlen(new_str)] = 34;
	free (str);
	return (new_str);
}
