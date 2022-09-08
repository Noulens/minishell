/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:57:27 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/08 17:20:37 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_struct(t_command *cm, char **envp, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	(void)envp;
	cm->cmd = NULL;
	cm->pid = -1;
	cm->end = NULL;
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
	cm->gb = NULL;
	cm->sigint = FALSE;
}
