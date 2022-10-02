/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:07:44 by waxxy             #+#    #+#             */
/*   Updated: 2022/10/02 19:11:34 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*gethdname(char *str)
{
	int		len;
	char	*p;

	len = ft_strlen(str);
	if (len <= 2 || isallspace(str + 2) == NULL)
		return (ft_putstr_fd(RED"heredoc : bad name\n"END, 2), NULL);
	else
	{
		p = ft_strdup(str + 2);
		if (!p)
			error_clean_up(g_ms);
		return (p);
	}
}

static char	*append_join(char *cmdline, char *data)
{
	char	*tmp;

	tmp = NULL;
	if (cmdline == NULL)
	{
		cmdline = ft_strdup(data);
		if (cmdline == NULL)
			return (perror("append_join"), NULL);
	}
	else
	{
		tmp = cmdline;
		cmdline = ft_strjoinsep(cmdline, data, " ");
		if (cmdline == NULL)
			return (free (tmp), perror("append_join"), NULL);
		free(tmp);
	}
	return (cmdline);
}

t_command	**malloc_pa(t_minishell *ms, int *j, t_tok **tmp, char **cmdline)
{
	int			i;
	t_command	**pa;

	i = 0;
	*j = 0;
	*tmp = ms->list;
	*cmdline = NULL;
	pa = (t_command **)ft_calloc(sizeof(t_command *), ms->nbr_cmd + 1);
	if (pa == NULL)
		error_clean_up(ms);
	while (i < ms->nbr_cmd)
	{
		pa[i] = (t_command *)malloc(sizeof(t_command));
		if (pa[i] == NULL)
		{
			free_param(pa);
			error_clean_up(ms);
		}
		init_struct(ms, pa[i]);
		i++;
	}
	return (pa);
}

int	ttok0(t_command **pa, int *i, char **cmdline)
{
	pa[*i]->cmd = ft_split(*cmdline, ' ');
	if (pa[*i]->cmd == NULL)
	{
		free(*cmdline);
		error_clean_up(g_ms);
	}
	free(*cmdline);
	*cmdline = NULL;
	pa[++*i] = NULL;
	return (0);
}

int	ttok356(t_tok *tmp, t_command **pa, int *i, char **cmdline)
{
	if (tmp->type == 3 && g_ms->sigint == FALSE)
	{
		if (pa[*i]->here_doc++ > 0)
			free(pa[*i]->limiter);
		pa[*i]->limiter = gethdname(tmp->data);
		if (pa[*i]->limiter != NULL)
			check_heredoc(pa, *i);
		g_ms->i.i = -1;
	}
	else if (tmp->type == 5)
	{
		*cmdline = append_join(*cmdline, tmp->data);
		if (!*cmdline)
			return (-1);
	}
	else if (tmp->type == 6)
	{
		pa[*i]->cmd = ft_split(*cmdline, ' ');
		if (pa[*i]->cmd == NULL)
			return (free(*cmdline), -1);
		free(*cmdline);
		*cmdline = NULL;
		return (++*i);
	}
	return (0);
}
