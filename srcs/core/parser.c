/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:09:29 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/20 18:27:28 by waxxy            ###   ########.fr       */
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

static char	*isallspace(char *str)
{
	char	*p;

	if (str == NULL)
		return (NULL);
	p = str;
	while (*p)
	{
		if (!ft_isspace(*p))
			return (p);
		p++;
	}
	return (NULL);
}

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

static char	*gethdname(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len <= 2 || isallspace(str + 2) == NULL)
		return (ft_putstr_fd(RED"heredoc : bad name\n"END, 2), NULL);
	else
		return (ft_strdup(str + 2));
}

static char	*append_join(char *cmdline, char *data)
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
		i++;
	}
	i = 0;
	while (i < ms->nbr_cmd)
	{
		while (tmp)
		{
			if (tmp->type == 0)
			{
				param[i]->cmd = ft_split(cmdline, ' ');
				free(cmdline);
				cmdline = NULL;
				param[++i] = NULL;
			}
			else if (tmp->type == 1)
			{
				if (param[i]->fd[0] <= 0)
				{
					param[i]->infile = getfilename(tmp->data, 1);
					if (param[i]->infile == NULL)
						return (perror("parse"), free_param(param), error_clean_up(ms), 1);
					param[i]->fd[0] = open(param[i]->infile, O_RDONLY);
					if (param[i]->fd[0] <= -1)
						perror("parse fd in open");
				}
				else
				{
					if (close(param[i]->fd[0]) == -1)
						perror("parse fd in close");
					if (param[i]->infile)
						free(param[i]->infile);
					param[i]->infile = getfilename(tmp->data, 1);
					if (param[i]->infile == NULL)
						return (perror("parse"), free_param(param), error_clean_up(ms), 1);
					param[i]->fd[0] = open(param[i]->infile, O_RDONLY);
					if (param[i]->fd[0] <= -1)
						perror("parse fd in open");
				}
			}
			else if (tmp->type == 2)
			{
				if (param[i]->fd[1] <= 1)
				{
					param[i]->outfile = getfilename(tmp->data, 2);
					if (param[i]->outfile == NULL)
						return (perror("parse"), free_param(param), error_clean_up(ms), 1);
					param[i]->fd[1] = open(param[i]->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
					if (param[i]->fd[1] <= -1)
						perror("parse fd out open");
				}
				else
				{
					if (close(param[i]->fd[1]) == -1)
						perror("parse fd out close");
					if (param[i]->outfile)
						free(param[i]->outfile);
					param[i]->outfile = getfilename(tmp->data, 2);
					if (param[i]->outfile == NULL)
						return (perror("parse"), free_param(param), error_clean_up(ms), 1);
					param[i]->fd[1] = open(param[i]->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
					if (param[i]->fd[1] <= -1)
						perror("parse fd out open");
				}
			}
			else if (tmp->type == 3)
			{
				if (param[i]->here_doc++ > 0)
					free(param[i]->limiter);
				param[i]->limiter = gethdname(tmp->data);
			}
			else if (tmp->type == 4)
			{
				if (param[i]->fd[1] <= 1)
				{
					param[i]->outfile = getfilename(tmp->data, 4);
					if (param[i]->outfile == NULL)
						return (perror("parse"), free_param(param), error_clean_up(ms), 1);
					param[i]->fd[1] = open(param[i]->outfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
					if (param[i]->fd[1] <= -1)
						perror("parse fd out append open");
				}
				else
				{
					if (close(param[i]->fd[1]) == -1)
						perror("parse fd out append close");
					if (param[i]->outfile)
						free(param[i]->outfile);
					param[i]->outfile = getfilename(tmp->data, 4);
					if (param[i]->outfile == NULL)
						return (perror("parse"), free_param(param), error_clean_up(ms), 1);
					param[i]->fd[1] = open(param[i]->outfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
					if (param[i]->fd[1] <= -1)
						perror("parse fd out append open");
				}
			}
			else if (tmp->type == 5)
			{
				cmdline = append_join(cmdline, tmp->data);
				if (!cmdline)
					return (free_param(param), error_clean_up(ms), 1);
			}
			else if (tmp->type == 6)
			{
				param[i]->cmd = ft_split(cmdline, ' ');
				free(cmdline);
				cmdline = NULL;
				i++;
			}
			tmp = tmp->next;
		}
	}
	ms->cm = param;
	return (0);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	ft_printf("res:%s\n", gethdname(argv[1]));
	return 0;
}*/
