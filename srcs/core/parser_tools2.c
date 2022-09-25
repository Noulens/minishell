/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:09:09 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/25 21:08:50 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*getfilename(char *str, int type)
{
	int		len;

	len = ft_strlen(str);
	if (type == 2 || type == 1)
	{
		if (len <= 1 || isallspace(str + 1) == NULL)
			return (ft_putstr_fd(RED"redirection : bad name\n"END, 2), NULL);
		else
			return (ft_strdup(str + 1));
	}
	else
	{
		if (len <= 2 || isallspace(str + 2) == NULL)
			return (ft_putstr_fd(RED"redirection : bad name\n"END, 2), NULL);
		else
			return (ft_strdup(str + 2));
	}
}

int	ttok4(t_tok *tmp, t_command **pa, int i)
{
	if (pa[i]->fd[1] <= 1)
	{
		pa[i]->o = getfilename(tmp->data, 4);
		if (pa[i]->o == NULL)
			return (2);
		pa[i]->fd[1] = open(pa[i]->o, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (pa[i]->fd[1] <= -1)
			perror("parse fd out append open");
	}
	else
	{
		if (close(pa[i]->fd[1]) == -1)
			perror("parse fd out append close");
		if (pa[i]->o)
			free(pa[i]->o);
		pa[i]->o = getfilename(tmp->data, 4);
		if (pa[i]->o == NULL)
			return (2);
		pa[i]->fd[1] = open(pa[i]->o, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (pa[i]->fd[1] <= -1)
			perror("parse fd out append open");
	}
	return (0);
}

int	ttok1(t_tok *tmp, t_command **pa, int i)
{
	if (pa[i]->fd[0] <= 0)
	{
		pa[i]->inf = getfilename(tmp->data, 1);
		if (pa[i]->inf == NULL)
			return (2);
		pa[i]->fd[0] = open(pa[i]->inf, O_RDONLY);
		if (pa[i]->fd[0] <= -1)
			perror("parse fd in open");
	}
	else
	{
		if (close(pa[i]->fd[0]) == -1)
			perror("parse fd in close");
		if (pa[i]->inf)
			free(pa[i]->inf);
		pa[i]->here_doc = FALSE;
		pa[i]->inf = getfilename(tmp->data, 1);
		if (pa[i]->inf == NULL)
			return (2);
		pa[i]->fd[0] = open(pa[i]->inf, O_RDONLY);
		if (pa[i]->fd[0] <= -1)
			perror("parse fd in open");
	}
	return (0);
}

int	ttok2(t_tok *tmp, t_command **pa, int i)
{
	if (pa[i]->fd[1] <= 1)
	{
		pa[i]->o = getfilename(tmp->data, 2);
		if (pa[i]->o == NULL)
			return (2);
		pa[i]->fd[1] = open(pa[i]->o, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (pa[i]->fd[1] <= -1)
			perror("parse fd out open");
	}
	else
	{
		if (close(pa[i]->fd[1]) == -1)
			perror("parse fd out close");
		if (pa[i]->o)
			free(pa[i]->o);
		pa[i]->o = getfilename(tmp->data, 2);
		if (pa[i]->o == NULL)
			return (2);
		pa[i]->fd[1] = open(pa[i]->o, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (pa[i]->fd[1] <= -1)
			perror("parse fd out open");
	}
	return (0);
}
