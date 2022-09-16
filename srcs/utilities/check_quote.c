/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:51:12 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/16 10:41:59 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
