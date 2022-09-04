/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:57:27 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/04 16:37:38 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    init_struct(t_command *cm, char **envp, int argc, char **argv)
{
    (void)argc;
    (void)argv;
    cm->cmd = NULL;
	cm->pid = -1;
	cm->end = NULL;
	cm->env = envp;
	cm->fd[0] = STDIN_FILENO;
    cm->fd[1] = STDOUT_FILENO;
	cm->here_doc = TRUE;
	cm->limiter = NULL;
	cm->pids = NULL;
	cm->end = NULL;
	cm->gb = NULL;
}
