/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:57:27 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/12 14:32:16 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_minishell(t_minishell *minishell)
{
	minishell->nbr_cmd = 0;
	minishell->cmd_array = NULL;
	minishell->exec_ret = 0;
	minishell->gb = NULL;
}

void	init_struct(t_command *cm, char **envp)
{
	cm->cmd = NULL;
	cm->pid = -1;
	cm->end = NULL;
	cm->env = envp;
	cm->fd[0] = STDIN_FILENO;
	cm->fd[1] = STDOUT_FILENO;
	cm->fdhd = -1;
	cm->here_doc = FALSE;
	cm->outfile_append = FALSE;
	cm->limiter = NULL;
	cm->infile = NULL;
	cm->outfile = NULL;
	cm->pids = NULL;
	cm->end = NULL;
	cm->sigint = FALSE;
}
