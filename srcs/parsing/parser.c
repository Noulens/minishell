/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:09:29 by waxxy             #+#    #+#             */
/*   Updated: 2022/10/12 12:28:40 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ias(char *str)
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

char	*expd(char *str, t_minishell *ms)
{
	char			*new_str;
	int				len;
	struct s_int	i;

	i.i = 0;
	i.j = 0;
	i.k = 0;
	len = 0;
	ms->i.i = 0;
	ms->i.j = 0;
	ms->i.k = 0;
	if (str == NULL)
		return (NULL);
	str = add_double_quote(str);
	if (str == NULL)
		return (ft_lstclear_tok(ms->list),
			clean_up(ms->gb, ms->env_array, ms->env),
			perror("malloc"), exit(errno), NULL);
	len = count_expender(i, str, ms);
	len += ft_strlen(str);
	new_str = init_expender(str, len, ms);
	if (new_str == NULL)
		return (NULL);
	free(str);
	new_str = suppr_double_quote(new_str);
	if (new_str == NULL)
		return (ft_lstclear_tok(ms->list),
			clean_up(ms->gb, ms->env_array, ms->env),
			perror("malloc"), exit(errno), NULL);
	return (new_str);
}

void	check_heredoc(t_command **pa, int i, t_minishell *ms)
{
	char	*p;
	int		tmp_fd;

	tmp_fd = open(".here_doc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd == -1 || tmp_fd > FOPEN_MAX)
		return (perror("check_heredoc open"), (void)0);
	pa[i]->fdhd = dup(STDIN_FILENO);
	g_ms->i.i = i;
	while (1 && g_ms->sigint == FALSE)
	{
		write(STDIN_FILENO, "heredoc> ", 9);
		p = get_next_line(pa[i]->fdhd);
		p = expd(p, ms);
		if (p == NULL || ft_strncmp(p, pa[i]->limiter, pa[i]->lim_len) == 0)
		{
			close(pa[i]->fdhd);
			if (p == NULL)
				ft_fprintf(2, "\nwarning: expected %s\n", pa[i]->limiter);
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
		else if (ttok356(tmp, pa, &i, ms) == -1)
			return (free_param(pa), error_clean_up(ms), 1);
		tmp = tmp->next;
	}
	return (0);
}
