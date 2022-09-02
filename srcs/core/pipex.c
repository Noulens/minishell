/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:54 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/02 20:27:57 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	nb_cmd(t_command *cm)
{
	int	i;

	i = 0;
	while (cm->cmd[i])
		i++;
	return (i);
}

int	child_mgmt(t_command *cm, int i, int *end, int cmd_nbr)
{
	char	**arg_cm;

	cm->pid = fork();
	if (cm->pid == -1)
		return (perror("child_mgmt"), errno);
	else if (!cm->pid)
	{
		if (cmd_nbr > 1)
		{
			if (i == 0)
				dupper(STDIN_FILENO, end[1]);
			else if (i == cmd_nbr - 1)
				dupper(end[2 * i - 2], STDOUT_FILENO);
			else
				dupper(end[2 * i - 2], end[2 * i + 1]);
		}
		close_pipes(cmd_nbr, end);
		arg_cm = ft_split(cm->cmd[i], ' ');
		if (gb_c(&cm->gb, NULL, (void **)arg_cm) == -1)
		{
			ft_lstclear(cm->gb);
			exit(errno);
		}
		cm->exec_ret = exec(arg_cm, cm->env);
		ft_lstclear(cm->gb);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	pipex(t_command *cm)
{
	int		cmd_nbr;
	int		*end;
	int		ret;
	int		i;

	cmd_nbr = nb_cmd(cm);
	if (cmd_nbr == 0)
		return (0);
	end = malloc(2 * sizeof(int) * (cmd_nbr - 1));
	if ((gb_c(&cm->gb, (void *)end, NULL) == -1 && cmd_nbr - 1 != 0) || open_pipes(cmd_nbr, end) != 0)
		return (perror("pipex"), errno);
	i = -1;
	while (cm->cmd[++i])
		child_mgmt(cm, i, end, cmd_nbr);
	close_pipes(cmd_nbr, end);
	i = -1;
	while (++i < cmd_nbr)
	{
		waitpid(-1, &ret, 0);
		if (WIFEXITED(ret))
			printf("P: exit ok: %d: %d\n", i, cm->exec_ret = WEXITSTATUS(ret));
		else
			printf("P: %d interrupted\n", i);
	}
	return (cm->exec_ret);
}
