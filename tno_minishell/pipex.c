/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:54 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/23 14:51:18 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	close_fd(int end[1024][2], int i)
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
	int		end[1024][2];
	char	**arg_cm;
	int		status;

	i = 0;
	while (cm->cmd[i])
		i++;
	if (i == 0)
		return (1);
	pid = malloc(sizeof(pid_t) * i);
	gb_c(cm->gb, (void *)pid, NULL);
	while (--i >= 0)
	{
		if (pipe(end[i]) < 0)
			return (perror("pipex"), errno);
	}
	i = -1;
	while (cm->cmd[++i])
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (perror("pipex"), errno);
		else if (pid[i] == 0)
		{
			arg_cm = ft_split(cm->cmd[i], ' ');
			gb_c(cm->gb, NULL, (void **)arg_cm);
			//int fd = open("file", O_CREAT | O_RDWR | O_TRUNC, 0777);
			//dup2(fd, STDOUT_FILENO);
			exec(arg_cm, cm->env);
		}
		else
		{
			waitpid(pid[i], &status, 0);
			printf("Parent : I received my %d child\n", i + 1);
			if (WIFEXITED(status))
				printf("Parent : It exited successfully, exit code %d\n", WEXITSTATUS(status));
            else
                printf("Parent : It was interrupted...\n");
		}
	}
	return (0);
}

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
}
