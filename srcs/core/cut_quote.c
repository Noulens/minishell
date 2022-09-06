/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:56:06 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/05 16:36:26 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_cut_line2(char *str, char *new_str, t_new_cut_line *line)
{
	if (str[(*line).i] == 34 || str[(*line).i] == 39)
	{
		if ((*line).trigger == 0)
		{
			(*line).c = str[(*line).i];
			(*line).i++;
			(*line).trigger++;
		}
	}
	if (str[(*line).i] != (*line).c)
	{
		new_str[(*line).j] = str[(*line).i];
		(*line).j++;
	}
	if (str[(*line).i] == (*line).c)
		(*line).trigger = 0;
}

char	*new_cut_line(char *str)
{
	char				*new_str;
	t_new_cut_line		line;
	int len;

	len = ft_strlen(str);
	line.i = 0;
	line.j = 0;
	line.trigger = 0;
	line.c = 0;
	new_str = calloc(sizeof(char), len);
	if (new_str == NULL)
		return (NULL);
	while (str[line.i] != 0)
	{
		new_cut_line2(str, new_str, &line);
		line.i++;
	}		
	free (str);
	return (new_str);
}

int	cut_quote(char **split_line)
{
	int		i;

	i = 0;
	while (split_line[i] != NULL)
	{
		split_line[i] = new_cut_line(split_line[i]);
		if (split_line[i] == NULL)
			return (perror("Malloc"), 1);
		i++;
	}
	return (0);
}
