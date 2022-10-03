/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_and_expend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:55:02 by cfontain          #+#    #+#             */
/*   Updated: 2022/10/03 16:52:40 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_pipe(t_minishell *ms)
{
	t_tok	*temp;

	temp = ms->list;
	if (ms->list)
	{
		while (ms->list != NULL)
		{
			if (ms->list->type == PIPE_LEX)
				ms->nbr_cmd++;
			ms->list = ms->list->next;
		}
	}
	ms->list = temp;
}

int	lexer_and_expend(char *p, t_minishell *minishell)
{
	if (lexer(p, minishell) == 1)
		return (1);
	if (expend_and_cut_quote(minishell) == 1)
		return (1);
	count_pipe(minishell);
	//printlist(minishell->list); //A SUPPRIMER A LA FIN
	//ft_printf("nombre de process : %d\n", minishell->nbr_cmd);
	return (0);
}
