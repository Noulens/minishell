/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:54 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/22 01:07:01 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	pipex(char **cmd, char **envp)
{
	int		i;
	pid_t	*pid;
	int		*end;

	i = 0;
	while (cmd[i])
		i++;
	pid = malloc(sizeof(pid_t) * i);
	end = malloc(sizeof(int) * i - 1);
	i = 0;
	while (cmd[i])
	{
		if (pipe(end) < 0)
			return (perror(errno), errno);
	}
}

int	main(int argc, char **argv, char **envp)
{
	return (0);
}
