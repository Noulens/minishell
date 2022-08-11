/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:34:33 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/21 11:44:42 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int	ft_child2(t_pipex *pipex, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		dup2(pipex->pipes[0], 0);
		dup2(pipex->data2.fdfile, 1);
		close(pipex->pipes[0]);
		close(pipex->pipes[1]);
		close(pipex->data1.fdfile);
		close(pipex->data2.fdfile);
		execve(pipex->data2.command_path, pipex->data2.command, env);
	}
	return (0);
}*/

int	ft_child1(t_command *command, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(command->path, command->argv, env) == -1)
			return (1);
		
	}
	return (0);
}

int	ft_fork(t_command *command, char **env)
{
	pid_t	wt;
	int		status;
	if (ft_child1(command, env) == 1)
		return (1);
	wt = wait(&status);
	if (wt == -1)
		return (ft_printf_error("Wait error\n"), 1);
	return (0);
}
