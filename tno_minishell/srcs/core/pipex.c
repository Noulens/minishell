/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:54 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/25 18:09:15 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	open_pipes(int cmd_nbr, int *end)
{
	int	i;

	i = 0;
	while (i < cmd_nbr - 1)
	{
		if (pipe(end + 2 * i) < 0)
			return(free(end), perror("open_pipes"), errno);
		i++;
	}
	return (0);
}

static int	close_pipes(int cmd_nbr, int *end)
{
	int	i;

	i = 0;
	while (i < cmd_nbr - 1)
	{
		if (close(end[i]) == -1)
			return (free(end), perror("close_pipes"), errno);
		i++;
	}
	return (0);
}

static void dupper(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

static int	nb_cmd(t_command *cm)
{
	int	i;
	
	i = 0;
	while (cm->cmd[i])
		i++;
	return (i);
}

int child_mgmt(t_command *cm, int i, int *end, int cmd_nbr)
{
	cm->pid = fork();
	if (cm->pid == -1)
		return (perror("pipex"), errno);
	else if (!cm->pid)
	{
		if (i == 0)
			dupper(STDIN_FILENO, end[1]);
		else if (i == cmd_nbr - 1)
			dupper(end[2 * i - 2], STDOUT_FILENO);
		else
			dupper(end[2 * i - 2], end[2 * i + 1]);
		close_pipes(cmd_nbr, end);
		// arg_cm = ft_split(cm->cmd[i], ' ');
		// gb_c(cm->gb, NULL, (void **)arg_cm);
		cm->exec_ret = exec(ft_split(cm->cmd[i], ' '), cm->env);
		return (0);
	}
	return (0);
}

int	pipex(t_command *cm)
{
	int		cmd_nbr;
	int		*end;
	//char	**arg_cm;
	int		status;
	int		i;

	cmd_nbr = nb_cmd(cm);
	if (cmd_nbr == 0)
		return (1);
	end = malloc(2 * sizeof(int) * (cmd_nbr - 1));
	if (!end && cmd_nbr - 1 != 0)
		return (perror("pipex"), errno);
	if (open_pipes(cmd_nbr, end) != 0)
		return (perror("pipex"), errno);
	i = -1;
	while (cm->cmd[++i])
		child_mgmt(cm, i, end, cmd_nbr);
	close_pipes(cmd_nbr, end);
	waitpid(-1, &status, 0);
	if (WIFEXITED(status))
		printf("P: exit success: %d\n", cm->exec_ret = WEXITSTATUS(status));
	else
		printf("P: interrupted\n");
	return (cm->exec_ret);
} 
