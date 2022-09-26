/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:44:09 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/26 15:27:10 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_clean_up(t_minishell *ms)
{
	ft_printf(RED"%s\n"END, strerror(errno));
	ft_lstclear(ms->gb);
	ft_lstclear(ms->env);
	ft_lstclear_tok(ms->list);
	free(ms->env_array);
	exit(137);
}

void	free_param(t_command **param)
{
	int	i;

	i = 0;
	while (param[i] != NULL)
	{
		ft_free_split(param[i]->cmd);
		free(param[i]->inf);
		free(param[i]->o);
		free(param[i]->limiter);
		free(param[i]);
		i++;
	}
	free(param);
}

void	clean_iteration(t_minishell *ms)
{
	ft_lstclear(ms->gb);
	ft_lstclear_tok(ms->list);
	free_param(ms->cm);
}

void	clean_up(t_list *lst, char **env_array, t_list *env)
{
	ft_lstclear(lst);
	ft_lstclear(env);
	free(env_array);
	return ;
}
