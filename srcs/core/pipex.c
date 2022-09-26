/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:54 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/26 22:58:25 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_fd_in(t_command *cm)
{
	if (cm->here_doc >= TRUE)
	{
		cm->fd[0] = open(".here_doc.tmp", O_RDONLY);
		if (cm->fd[0] == -1)
			perror("get_fd_in");
	}
}

int	child_mgmt(int i, int cmd_nbr, t_minishell *ms)
{
	ms->pids[i] = fork();
	if (ms->pids[i] == -1)
		return (perror("child_mgmt"), errno);
	else if (!ms->pids[i])
	{
		get_fd_in(ms->cm[i]);
		if (i == 0 && cmd_nbr == 1)
			dupper(ms->cm[i]->fd[0], ms->cm[i]->fd[1]);
		else if (i == 0)
			dupper(ms->cm[i]->fd[0], ms->end[1]);
		else if (i == cmd_nbr - 1)
			dupper(ms->end[2 * i - 2], ms->cm[i]->fd[1]);
		else
			dupper(ms->end[2 * i - 2], ms->end[2 * i + 1]);
		close_pipes(cmd_nbr, ms->end, ms->cm[i]);
		ms->exec_ret = exec(ms, ms->cm[i]->cmd, ms->cm[i]->env);
		close_std_in_child(ms, i);
		clean_up(ms->gb, ms->env_array, ms->env);
		ft_lstclear_tok(ms->list);
		free_param(ms->cm);
		exit(ms->exec_ret);
	}
	return (0);
}

int	malloc_pids(t_minishell *ms)
{
	ms->pids = (pid_t *)malloc(ms->nbr_cmd * sizeof(pid_t));
	if (gb_c(&ms->gb, (void *)ms->pids, NULL) == -1)
		return (perror("pipex pids"), errno);
	ms->end = malloc(2 * sizeof(int) * (ms->nbr_cmd - 1) + 2 * sizeof(int));
	if ((gb_c(&ms->gb, (void *)ms->end, NULL) == -1 && ms->nbr_cmd - 1 != 0)
		|| open_pipes(ms->nbr_cmd, ms->end) != 0)
		return (perror("pipex end"), errno);
	return (0);
}

int	is_built(t_minishell *ms, char *str)
{
	int			i;
	t_builtin	built[7];

	i = 0;
	init_builtin(built);
	while (i < NBR_BI)
	{
		if (!ft_strncmp(str, built[i].name, 10))
		{
			ms->i.j = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int	built_mgmt(t_minishell *ms, int argc, char **argv)
{
	int			fdin;
	int			fdout;
	t_builtin	built[7];

	init_builtin(built);
	fdin = dup(STDIN_FILENO);
	fdout = dup(STDOUT_FILENO);
	dup2(ms->cm[0]->fd[0], STDIN_FILENO);
	dup2(ms->cm[0]->fd[1], STDOUT_FILENO);
	ms->exec_ret = built[ms->i.j].func(ms, argc, argv);
	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	close(fdin);
	close(fdout);
	if (ms->cm[0]->fd[0] != STDIN_FILENO)
		close(ms->cm[0]->fd[0]);
	if (ms->cm[0]->fd[1] != STDOUT_FILENO)
		close(ms->cm[0]->fd[1]);
	return (0);
}

int	pipex(t_minishell *ms)
{
	int		ret;
	int		i;

	if (ms->nbr_cmd == 1 && is_built(ms, ms->cm[0]->cmd[0]))
	{
		built_mgmt(ms, nb_cmd(ms->cm[0]->cmd), ms->cm[0]->cmd);
		return (ms->exec_ret);
	}
	if (malloc_pids(ms) != 0)
		return (error_clean_up(ms), -1);
	i = -1;
	while (++i < ms->nbr_cmd && ms->sigint == FALSE)
		child_mgmt(i, ms->nbr_cmd, ms);
	close_pipes_parent(ms->nbr_cmd, ms->end, ms);
	i = -1;
	while (++i < ms->nbr_cmd && ms->sigint == FALSE)
	{
		waitpid(ms->pids[i], &ret, 0);
		if (WIFEXITED(ret))
			ft_printf("P %d, exit ok: %d\n", i, ms->exec_ret = WEXITSTATUS(ret));
		else
		{
			ms->exec_ret = errno;
			ft_printf("P %d, interrupted\n", i);
		}
	}
	return (ms->exec_ret);
}
