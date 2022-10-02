/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:28:09 by waxxy             #+#    #+#             */
/*   Updated: 2022/10/01 17:13:52 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_fd_in(t_command *cm)
{
	if (cm->here_doc >= TRUE)
	{
		cm->fd[0] = open(".here_doc.tmp", O_RDONLY);
		if (cm->fd[0] == -1 || cm->fd[0] > FOPEN_MAX)
			perror("get_fd_in");
	}
}

int	nb_cmd(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return (0);
	else
	{
		while (argv[i])
			i++;
	}
	return (i);
}
