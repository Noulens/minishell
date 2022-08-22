/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:54 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/22 14:47:27 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	pipex(t_list **gb, char **cmd, char **envp)
{
	int		i;
	pid_t	*pid;
	int		end[1024][2];
	char	**arg_to_exec;

	i = 0;
	while (cmd[i])
		i++;
	if (i == 0)
		return (1);
	pid = malloc(sizeof(pid_t) * i);
	while (i)
	{
		if (pipe(end[i]) < 0)
			return (perror(errno), errno);
		i--;
	}
	i = 0
	while (cmd[i])
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (perror(errno), errno);
		else if (pid[i] == 0)
		{
			dup2()
			dup2()
			close()
			close()
			arg_to_exec = ft_split(cmd[i], ' ');
			gb_c(gb, NULL, arg_to_exec);
			exec(arg_to_exec[0], envp);
		}
	}
}
