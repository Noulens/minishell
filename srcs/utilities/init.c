/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:57:27 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/06 14:45:50 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_struct(t_command *cm, char **envp, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	cm->cmd = NULL;
	cm->pid = -1;
	cm->end = NULL;
	cm->env = envp;
	cm->fd[0] = STDIN_FILENO;
	cm->fd[1] = STDOUT_FILENO;
	cm->fdhd = -1;
	cm->here_doc = FALSE;
	cm->limiter = NULL;
	cm->pids = NULL;
	cm->end = NULL;
	cm->gb = NULL;
	cm->sigint = FALSE;
}
