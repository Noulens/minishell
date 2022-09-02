/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:57:27 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/02 20:03:40 by waxxy            ###   ########.fr       */
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
	cm->fd[0] = -1;
    cm->fd[1] = -1;
	cm->here_doc = 0;
	cm->exec_ret = -1;
	cm->gb = NULL;
}
