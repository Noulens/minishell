/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:09:29 by waxxy             #+#    #+#             */
/*   Updated: 2022/10/01 16:53:37 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*isallspace(char *str)
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

void	check_heredoc(t_command **pa, int i)
{
	char	*p;
	int		tmp_fd;

	tmp_fd = open(".here_doc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd == -1)
		return (perror("check_heredoc open"), (void)0);
	pa[i]->fdhd = dup(STDIN_FILENO);
	g_ms->i.i = i;
	while (1 && g_ms->sigint == FALSE)
	{
		write(STDIN_FILENO, "heredoc> ", 9);
		p = get_next_line(pa[i]->fdhd);
		if (p == NULL || ft_strcmp(p, pa[i]->limiter) - 10 == 0)
		{
			close(pa[i]->fdhd);
			if (p == NULL)
				ft_printf("warning: expected %s\n", pa[i]->limiter);
			free(p);
			break ;
		}
		ft_putstr_fd(p, tmp_fd);
		free(p);
	}
	close(tmp_fd);
}

int	parse(t_minishell *ms)
{
	t_command	**pa;
	t_tok		*tmp;
	int			i;

	pa = malloc_pa(ms, &i, &tmp);
	g_ms->i.i = -1;
	if (pa == NULL)
		return (1);
	ms->cm = pa;
	while (tmp)
	{
		if (tmp->type == 0)
			ttok0(pa, &i);
		else if (tmp->type == 1 && ttok1(tmp, pa, i) == 1)
			return (1);
		else if (tmp->type == 2 && ttok2(tmp, pa, i) == 1)
			return (1);
		else if (tmp->type == 4 && ttok4(tmp, pa, i) == 1)
			return (1);
		else if (ttok356(tmp, pa, &i) == -1)
			return (free_param(pa), error_clean_up(ms), 1);
		tmp = tmp->next;
	}
	return (0);
}

//int	parse(t_minishell *ms)
//{
//	t_command	**pa;
//	t_tok		*tmp;
//	char		*cmdline;
//	int			i;
//
//	pa = malloc_pa(ms, &i, &tmp, &cmdline);
//	g_ms->i.i = -1;
//	if (pa == NULL)
//		return (1);
//	ms->cm = pa;
//	while (tmp)
//	{
//		if (tmp->type == 0)
//			ttok0(pa, &i, &cmdline);
//		else if (tmp->type == 1 && ttok1(tmp, pa, i) == 1)
//			return (1);
//		else if (tmp->type == 2 && ttok2(tmp, pa, i) == 1)
//			return (1);
//		else if (tmp->type == 4 && ttok4(tmp, pa, i) == 1)
//			return (1);
//		else if (ttok356(tmp, pa, &i, &cmdline) == -1)
//			return (free_param(pa), error_clean_up(ms), 1);
//		tmp = tmp->next;
//	}
//	return (0);
//}
