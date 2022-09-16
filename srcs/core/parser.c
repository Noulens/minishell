/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:09:29 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/16 17:58:59 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
# define END_LEX 0
# define STDIN_LEX 1
# define STDOUT_LEX 2
# define HEREDOC_LEX 3
# define APPEND_LEX 4
# define CMD_LEX 5
# define PIPE_LEX 6

int	countcmd(t_tok *tok)
{
	int		k;
	t_tok	*tmk;

	tmk = tok;
	k = 0;
	while (tmk)
	{
		if (tmk->type = 6 && tmk->next->type != 6 && tmk->next->type != 0)
			k++;
	}
}*/

char	*append_join(char *cmdline, char *data)
{
	char	*tmp;

	tmp = NULL;
	if (cmdline == NULL)
		cmdline = ft_strjoinsep(data, "", "");
	else
	{
		tmp = cmdline;
		cmdline = ft_strjoinsep(cmdline, data, " ");
		free(tmp);
		if (cmdline == NULL)
			return (perror("append_join"), NULL);
	}
	return (cmdline);
}

int	parse(t_minishell *ms)
{
	t_command	**param;
	t_tok		*tmp;
	char		*cmdline;
	int			i;

	param = (t_command **)ft_calloc(sizeof(t_command *), ms->nbr_cmd + 1);
	if (param == NULL)
		return (perror("parse"), error_clean_up(ms), 1);
	i = 0;
	tmp = ms->list;
	cmdline = NULL;
	while (i < ms->nbr_cmd)
	{
		param[i] = (t_command *)malloc(sizeof(t_command));
		if (param[i] == NULL)
			return (perror("parse"), free_param(param), error_clean_up(ms), 1);
		init_struct(ms, param[i]);
		while (tmp)
		{
			if (tmp->type == 0)
				param[++i] == NULL;
			else if (tmp->type == 1)
				/* do this */;
			else if (tmp->type == 2)
				/* do this */;
			else if (tmp->type == 3)
				/* do this */;
			else if (tmp->type == 4)
				/* do this */;
			else if (tmp->type == 5)
			{
				cmdline = append_join(cmdline, tmp->data);
				if (!cmdline)
					return (free_param(param), error_clean_up(ms), 1);
			}
			else if (tmp->type == 6)
				i++;
			tmp = tmp->next;
		}
	}
		//char	**cmd;
		char	*infile;
		char	*outfile;
		char	**env;
		pid_t	pid;
		pid_t	*pids;
		int		*end;
		int		fd[2];
		int		fdhd;
		short	here_doc;
		short	outfile_append;
		char	*limiter;
		int		exec_ret;
		short	sigint;
}
