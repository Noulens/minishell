/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:06:11 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/06 16:36:21 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	rmvone(t_command **pa, int i)
{
	t_list	*tmp;

	tmp = pa[i]->cmdlst;
	pa[i]->cmdlst = pa[i]->cmdlst->next;
	free(tmp->content);
	free(tmp);
}

int	checkforenvvar(t_command **pa, int *i)
{
	char	**p;
	int		k;

	p = NULL;
	if (ias(pa[*i]->cmd[0])
		&& ft_memchr(pa[*i]->cmd[0], ' ', ft_strlen(pa[*i]->cmd[0])))
	{
		p = ft_split(pa[*i]->cmd[0], ' ');
		if (p == NULL)
			return (-1);
		k = nb_cmd(p);
		rmvone(pa, *i);
		while (--k, k >= 0)
		{
			ft_lstadd_front(&pa[*i]->cmdlst, ft_lstnew(ft_strdup(p[k]), NULL));
			if (pa[*i]->cmdlst->content == NULL || pa[*i]->cmdlst == NULL)
				return (ft_free_split(p), -1);
		}
		if (list_to_cmd(pa, *i) == -1)
			return (ft_free_split(p), -1);
	}
	return (ft_free_split(p), 0);
}

static void	swap(t_list *a, t_list *b)
{
	char	*temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

void	bubblesortlist(t_list *start)
{
	short	swapped;
	t_list	*ptr1;
	t_list	*lptr;

	swapped = 1;
	lptr = NULL;
	while (swapped)
	{
		swapped = 0;
		ptr1 = start;
		while (ptr1->next != lptr)
		{
			if (ft_strcmp(ptr1->content, ptr1->next->content) > 0)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

char	*genv(t_minishell *ms, char *p)
{
	int	i;

	i = 0;
	while (ms->env_array[i])
	{
		if (!ft_cmpchr(ms->env_array[i], p, '='))
			return (ft_strchr(ms->env_array[i], '=') + 1);
		i++;
	}
	return (NULL);
}
