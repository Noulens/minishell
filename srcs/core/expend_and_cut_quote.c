/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_and_cut_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:11:25 by cfontain          #+#    #+#             */
/*   Updated: 2022/10/05 16:30:37 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dup_without_quote(char *str, char *new_str, int i, int j)
{
	char	c;
	int		trigger;

	trigger = 0;
	c = 0;
	while (str[i] != 0)
	{
		if (char_is_quote(str[i]) == 0 && check_quote(str, i) == 0
			&& trigger == 0)
		{
			c = str[i];
			trigger++;
			i++;
		}
		if (str[i] == c)
		{
			i++;
			trigger = 0;
			continue ;
		}	
		new_str[j] = str[i];
		j++;
		i++;
	}
	return (0);
}

char	*dup_without_quote_init(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	new_str = calloc(sizeof(char), (ft_strlen(str) + 1));
	if (new_str == NULL)
		return (NULL);
	dup_without_quote(str, new_str, i, j);
	return (new_str);
}

char	*str_with_one_space(char *str2)
{
	str2 = calloc(sizeof(char), 2);
	if (str2 == NULL)
		return (NULL);
	str2[0] = ' ';
	return (str2);
}

char	**list_to_export_tok(t_minishell *ms)
{
	t_tok	*tmp;
	size_t	idx;
	char	**empty_str;

	idx = ft_lstsize_tok(ms->list);
	empty_str = (char **)ft_calloc(sizeof(char *), idx + 1);
	if (!empty_str)
		return (perror("list_to_array"), NULL);
	tmp = ms->list;
	idx = 0;
	while (tmp != NULL)
	{
		if (ft_strchr(tmp->data, '\0'))
		{
			empty_str[idx] = tmp->data;
			idx++;
		}
		tmp = tmp->next;
	}
	return (empty_str);
}

int	ft_unset_tok(t_minishell *ms);

int	cut_quote(t_minishell *minishell)
{
	char	*str2;
	t_tok	*temp;

	temp = minishell->list;
	while (minishell->list)
	{
		str2 = dup_without_quote_init(minishell->list->data);
		if (str2 == NULL)
			return (1);
		free (minishell->list->data);
		minishell->list->data = str2;
		minishell->list = minishell->list->next;
	}
	minishell->list = temp;
	ft_lstadd_back_tok(&minishell->list, ft_lstnew_tok(NULL, END_LEX));
	return (0);
}	

int	expend_and_cut_quote(t_minishell *minishell)
{
	char	*str;
	char	*str2;
	t_tok	*temp;

	temp = minishell->list;
	while (minishell->list)
	{
		str = expend_alias(minishell->list->data, minishell);
		if (str == NULL)
			return (1);
		free (minishell->list->data);
		minishell->list->data = str;
		minishell->list = minishell->list->next;
	}
	minishell->list = temp;
	ft_unset_tok(minishell);
	if (cut_quote(minishell) == 1)
		return (1);
	return (0);
}

static int	find_idx_tok(t_tok *tok, char *arg)
{
	int		i;
	t_tok	*p;

	(void)arg;
	i = 0;
	p = tok;
	while (p)
	{
		if (ft_strchr(p->data, 0) == p->data)
			return (i);
		p = p->next;
		i++;
	}
	return (-1);
}

static void	del_idx_0_tok(t_minishell *ms)
{
	t_tok	*tmp;

	tmp = ms->list;
	ms->list = ms->list->next;
	free(tmp->data);
	free(tmp);
}

static void	del_idx_pos_tok(t_minishell *ms, int idx)
{
	t_tok	*tmp;
	t_tok	*tmp2;

	tmp2 = ms->list;
	while (idx--)
	{
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	tmp->next = tmp2->next;
	free(tmp2->data);
	free(tmp2);
}

int	ft_unset_tok(t_minishell *ms)
{
	int		i;
	int		idx;
	char	**argv;

	argv = list_to_export_tok(ms);
	i = 0;
	while (argv[i] != NULL)
	{
		idx = find_idx_tok(ms->list, argv[i]);
		if (idx == -1)
		{
			i++;
			continue ;
		}
		if (idx == 0)
			del_idx_0_tok(ms);
		else if (idx > 0)
			del_idx_pos_tok(ms, idx);
		i++;
	}
	free(argv);
	return (SUCCESS);
}
