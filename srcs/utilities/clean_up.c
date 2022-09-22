/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:44:09 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/22 15:20:18 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_clean_up(t_minishell *ms)
{
	strerror(errno);
	ft_lstclear(ms->gb);
	ft_lstclear(ms->env);
	ft_lstclear_tok(ms->list);
	free(ms->env_array);
	exit(EXIT_FAILURE);
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

void	clean_up(t_list *lst, char **env_array, t_list *env)
{
	ft_lstclear(lst);
	ft_lstclear(env);
	free(env_array);
	return ;
}
