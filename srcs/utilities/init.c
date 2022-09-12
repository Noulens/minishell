/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:57:27 by waxxy             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/12 14:32:16 by cfontain         ###   ########.fr       */
=======
/*   Updated: 2022/09/09 17:58:29 by tnoulens         ###   ########.fr       */
>>>>>>> 028d83a75eff617d6a570501db96db6e715f6eeb
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
void	init_minishell(t_minishell *minishell)
{
	minishell->nbr_cmd = 0;
	minishell->cmd_array = NULL;
	minishell->exec_ret = 0;
	minishell->gb = NULL;
}

void	init_struct(t_command *cm, char **envp)
=======
void	init_struct(t_minishell *ms, t_command *cm)
>>>>>>> 028d83a75eff617d6a570501db96db6e715f6eeb
{
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
<<<<<<< HEAD
	cm->end = NULL;
=======
	cm->env = ms->env;
	cm->gb = NULL;
>>>>>>> 028d83a75eff617d6a570501db96db6e715f6eeb
	cm->sigint = FALSE;
}
