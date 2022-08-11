/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_triple_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:44:49 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/04 14:08:53 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_triple_join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (str == NULL)
		return (ft_printf_error("Error\nMalloc failed\n"), NULL);
	while (s1[++i] != 0)
		str[i] = s1[i];
	str[i] = '/';
	i++;
	while (s2[j] != 0)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}
