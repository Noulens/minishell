/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:54 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/24 20:04:27 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	open_fd(int end[MAX_PIPE + 1][2], int i)
{
	while (--i >= 0)
	{
		if (pipe(end[i]) < 0)
			return (perror("pipex"), errno);
	}
	return (0);
}

int	close_fd(int end[MAX_PIPE + 1][2], int i)
{
	while (--i >= 0)
	{
		if (close(end[i][0]) == -1)
			return (perror("close fd"), errno);
		if (close(end[i][1]) == -1)
			return (perror("close_fd"), errno);
	}
	return (0);
}

int	pipex(t_command *cm)
{
	int		i;
	pid_t	*pid;
	int		end[MAX_PIPE + 1][2];
	char	**arg_cm;
	int		status;
	int		k;

	i = 0;
	while (cm->cmd[i])
		i++;
	if (i == 0)
		return (1);
	pid = malloc(sizeof(pid_t) * i);
	if (!pid)
		return (1);
	k = i - 1;
	gb_c(cm->gb, (void *)pid, NULL);
	if (k != 0) {
	while (--k >= 0)
	{
		if (pipe(end[k]) < 0)
			return (perror("pipex"), errno);
	} }
	i = -1;
	while (cm->cmd[++i])
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (perror("pipex"), errno);
		else if (pid[i] == 0)
		{
			if (i != 1 && k != 0) {dup2(end[i][1], i + 1);
			close(end[i][1]);
			close(end[i][0]);}
			else if (k != 0) {dup2(end[i - 1][0], i - 1);
			close(end[i-1][0]);
			close(end[i-1][1]);}
			arg_cm = ft_split(cm->cmd[i], ' ');
			gb_c(cm->gb, NULL, (void **)arg_cm);
			cm->exec_ret = exec(arg_cm, cm->env);
            return 0;
		}
		else
		{
			close_fd(end, i);
			waitpid(pid[i], &status, 0);
			printf("P: received %d child\n", i + 1);
			if (WIFEXITED(status))
				printf("P: exit success: %d\n", cm->exec_ret = WEXITSTATUS(status));
			else
				printf("P: interrupted\n");
		}
	}
	return (0);
}

/*
int main(int argc, char **argv, char **envp)
{
	t_command cm;
	t_list		*list;
	
	(void)argc;
	list = NULL;
	cm.env = envp;
	cm.gb = &list;
	cm.cmd = ++argv;
	pipex(&cm);
	ft_lstclear(*(cm.gb));
	return (0);
}*/
