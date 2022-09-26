/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:06:24 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/26 23:19:08 by waxxy            ###   ########.fr       */
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
	if (cm->here_doc >= TRUE)
	{
		close(cm->fd[0]);
		unlink(".here_doc.tmp");
	}
	else if (cm->fd[0] != STDIN_FILENO)
	{
		if (close(cm->fd[0]) == -1)
			return (perror("close_std_in_child fd[0]"), errno);
	}
	if (cm->fd[1] != STDOUT_FILENO)
	{
		if (close(cm->fd[1]) == -1)
			return (perror("close_std_in_child fd[1]"), errno);
	}
	return (0);
}

int	close_pipes_parent(int cmd_nbr, int *end, t_minishell *ms)
{
	int	i;

	i = 0;
	while (i < 2 * (cmd_nbr))
	{
		if (close(end[i]) == -1)
			return (perror("close_pipes"), errno);
		i++;
	}
	i = 0;
	while (ms->cm[i] != NULL)
	{
		if (ms->cm[i]->fd[0] != STDIN_FILENO)
		{
			if (close(ms->cm[i]->fd[0]) == -1)
				return (perror("close_pipes"), errno);
		}
		if (ms->cm[i]->fd[1] != STDOUT_FILENO)
		{
			if (close(ms->cm[i]->fd[1]) == -1)
				return (perror("close_pipes"), errno);
		}
		i++;
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

void	close_std_in_child(t_minishell *ms, int i)
{
	(void)i;
	(void)ms;
	//if (ms->cm[i]->fd[0] != STDIN_FILENO && ms->cm[i]->here_doc == FALSE)
	//{
	//	if (close(ms->cm[i]->fd[0]) == -1)
	//		return (perror("close_std_in_child fd[0]"), (void)0);
	//}
	//if (ms->cm[i]->fd[1] != STDIN_FILENO)
	//{
	//	ft_putnbr_fd(ms->cm[i]->fd[1], 2);
	//	if (close(ms->cm[i]->fd[1]) == -1)
	//		return (perror("close_std_in_child fd[1]"), (void)0);
	//}
	if (close(0) == -1)
		return (perror("close_std_in_child"), (void)0);
	if (close(1) == -1)
		return (perror("close_std_in_child"), (void)0);
	if (close(2) == -1)
		return (perror("close_std_in_child"), (void)0);
}
