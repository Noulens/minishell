/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:54 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/06 16:28:12 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	nb_cmd(t_command *cm)
{
	int	i;

	i = 0;
	while (cm->cmd[i])
		i++;
	return (i);
}

int	child_mgmt(t_command *cm, int i, int cmd_nbr)
{
	char	**arg_cm;

	cm->pids[i] = fork();
	if (cm->pids[i] == -1)
		return (perror("child_mgmt"), errno);
	else if (!cm->pids[i])
	{
		if (i == 0 && cmd_nbr == 1)
			dupper(cm->fd[0], cm->fd[1]);
		else if (i == 0)
			dupper(cm->fd[0], cm->end[1]);
		else if (i == cmd_nbr - 1)
			dupper(cm->end[2 * i - 2], STDOUT_FILENO);
		else
			dupper(cm->end[2 * i - 2], cm->end[2 * i + 1]);
		close_pipes(cmd_nbr, cm->end, cm);
		arg_cm = ft_split(cm->cmd[i], ' ');
		if (gb_c(&cm->gb, NULL, (void **)arg_cm) == -1)
			return (ft_lstclear(cm->gb), exit(errno), errno);
		cm->exec_ret = exec(arg_cm, cm->env);
		close_std_in_child();
		clean_up(cm->gb, cm->env);
		exit(cm->exec_ret);
	}
	return (0);
}

void	check_heredoc(t_command *cm)
{
	char	*p;
	int		stdin_fd;
	int		tmp_fd;

	tmp_fd = open(".here_doc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd == -1)
		return (perror("check_heredoc open"), (void)0);
	stdin_fd = dup(STDIN_FILENO);
	cm->fdhd = stdin_fd;
	while (1)
	{
		write(STDIN_FILENO, "heredoc> ", 9);
		p = get_next_line(stdin_fd);
		if (p == NULL || !ft_strncmp(p, "stop", 4))
		{
			close(stdin_fd);
			if (p == NULL)
				ft_printf("warning: expected stop\n");
			free(p);
			break ;
		}
		ft_putstr_fd(p, tmp_fd);
		free(p);
	}
	close(tmp_fd);
}

void	get_fd_in(t_command *cm)
{
	if (cm->here_doc == TRUE)
	{
		check_heredoc(cm);
		cm->fd[0] = open(".here_doc.tmp", O_RDONLY);
		if (cm->fd[0] == -1)
			perror("get_fd_in");
	}
}

int	pipex(t_command *cm)
{
	int		cmd_nbr;
	int		ret;
	int		i;

	cmd_nbr = nb_cmd(cm);
	if (cmd_nbr == 0)
		return (0);
	get_fd_in(cm);
	cm->pids = (pid_t *)malloc(cmd_nbr * sizeof(pid_t));
	if (gb_c(&cm->gb, (void *)cm->pids, NULL) == -1)
		return (perror("pipex pids"), errno);
	cm->end = (int *)malloc(2 * sizeof(int) * (cmd_nbr - 1) + 2 * sizeof(int));
	if ((gb_c(&cm->gb, (void *)cm->end, NULL) == -1 && cmd_nbr - 1 != 0) || open_pipes(cmd_nbr, cm->end) != 0)
		return (perror("pipex end"), errno);
	i = -1;
	while (cm->cmd[++i] && cm->sigint == FALSE)
		child_mgmt(cm, i, cmd_nbr);
	close_pipes(cmd_nbr, cm->end, cm);
	i = -1;
	while (++i < cmd_nbr && cm->sigint == FALSE)
	{
		waitpid(cm->pids[i], &ret, 0);
		if (WIFEXITED(ret))
			printf("P %d, exit ok: %d\n", i, cm->exec_ret = WEXITSTATUS(ret));
		else
		{
			cm->exec_ret = errno;
			printf("P %d, interrupted\n", i);
		}
	}
	return (cm->exec_ret);
}
