/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_parsing_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:51:12 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/30 16:14:34 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_single_quote(char *str, int *i)
{
	(*i)++;
	while (str[(*i)] != 0 && str[(*i)] != 39)
		(*i)++;
	if (str[(*i)] != 39)
		return (1);
	return (0);
}

int	check_double_quote(char *str, int *i)
{
	(*i)++;
	while (str[(*i)] != 0 && str[(*i)] != 34)
		(*i)++;
	if (str[(*i)] != 34)
		return (1);
	return (0);
}

int	parsing_quote(char *str)
{
	int		i;

	i = 0;
	if (str[i] == 34)
	{
		if (check_double_quote(str, &i) == 1)
			return (1);
	}
	if (str[i] == 39)
	{
		if (check_single_quote(str, &i) == 1)
			return (1);
	}
	return (0);
}
