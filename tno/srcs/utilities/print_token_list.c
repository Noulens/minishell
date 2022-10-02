/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:48:20 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/16 10:40:38 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token_type(int i) //NE PAS GARDER A LA FIN
{
	if (i == END_LEX)
		ft_printf(" ***END_TYPE***\n");
	if (i == STDIN_LEX)
		ft_printf(" ***STDIN_TYPE***\n");
	if (i == STDOUT_LEX)
		ft_printf(" ***STDOUT_TYPE***\n");
	if (i == HEREDOC_LEX)
		ft_printf(" ***HEREDOC_TYPE***\n");
	if (i == APPEND_LEX)
		ft_printf(" ***APPEND_TYPE***\n");
	if (i == PIPE_LEX)
		ft_printf(" ***PIPE_TYPE***\n");
	if (i == CMD_LEX)
		ft_printf(" ***CMD_TYPE***\n");
}

void	printlist(t_tok *list) // NE PAS GARDER A LA FIN
{
	if (list)
	{
		while (list != NULL)
		{
			if (list->data != NULL)
				ft_printf("[%s]", list->data);
			else
				ft_printf("<end node>");
			print_token_type(list->type);
			list = list->next;
		}
	}
}
