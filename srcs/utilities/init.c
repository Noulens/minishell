/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:57:27 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/20 16:23:44 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_builtin(t_builtin *built)
{
	ft_strlcpy(built[0].name, "echo", 5);
	ft_strlcpy(built[1].name, "env", 4);
	ft_strlcpy(built[2].name, "exit", 5);
	ft_strlcpy(built[3].name, "export", 7);
	ft_strlcpy(built[4].name, "pwd", 4);
	ft_strlcpy(built[5].name, "unset", 6);
	ft_strlcpy(built[6].name, "cd", 3);
	built[0].func = ft_echo;
	built[1].func = ft_env;
	built[2].func = ft_exit;
	built[3].func = ft_export;
	built[4].func = ft_pwd;
	built[5].func = ft_unset;
	built[6].func = ft_cd;
}

void	init_minishell(t_minishell *minishell)
{
	t_builtin	built[7];

	minishell->nbr_cmd = 1;
	minishell->cmd_array = NULL;
	minishell->exec_ret = 0;
	minishell->gb = NULL;
	minishell->env = NULL;
	minishell->env_array = NULL;
	minishell->list = NULL;
	minishell->local_env = NULL;
	minishell->bi = built;
	minishell->sigint = FALSE;
	init_builtin(built);
}

void	init_struct(t_minishell *ms, t_command *cm)
{
	cm->cmd = NULL;
	cm->pid = -1;
	cm->end = NULL;
	cm->fd[0] = STDIN_FILENO;
	cm->fd[1] = STDOUT_FILENO;
	cm->fdhd = -1;
	cm->here_doc = FALSE;
	cm->limiter = NULL;
	cm->infile = NULL;
	cm->outfile = NULL;
	cm->pids = NULL;
	cm->env = ms->env_array;
	cm->sigint = ms->sigint;
}
/*
	char	**cmd; ok
	char	*infile; ok
	char	*outfile; ok
	char	**env; ok
	pid_t	pid; ok
	pid_t	*pids; ok
	int		*end; ok
	int		fd[2]; ok
	int		fdhd; ok
	short	here_doc; ok
	short	outfile_append; ok
	char	*limiter; ok
	int		exec_ret; NOPE
	short	sigint; ok
*/
