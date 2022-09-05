/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:06:24 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/05 16:37:18 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_pipes(int cmd_nbr, int *end)
{
	int	i;

	i = 0;
	while (i < cmd_nbr)
	{
		if (pipe(end + 2 * i) < 0)
			return (perror("open_pipes"), errno);
		i++;
	}
	return (0);
}

int	close_pipes(int cmd_nbr, int *end, t_command *cm)
{
	int	i;

	i = 0;
	while (i < 2 * (cmd_nbr))
	{
		if (close(end[i]) == -1)
			return (perror("close_pipes"), errno);
		i++;
	}
	if (cm->here_doc == TRUE)
	{
		close(cm->fd[0]);
		unlink(".here_doc.tmp");
	}
	return (0);
}

void	dupper(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
		return (perror("dupper input"), (void)0);
	if (dup2(output, STDOUT_FILENO) == -1)
		return (perror("dupper output"), (void)0);
}
