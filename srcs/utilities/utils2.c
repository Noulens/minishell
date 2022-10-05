/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:06:11 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/05 15:59:42 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checkforenvvar(t_command **pa, int *i)
{
	char	**p;
	t_list	*tmp;
	int		k;

	if (isallspace(pa[*i]->cmd[0])
		&& ft_memchr(pa[*i]->cmd[0], ' ', ft_strlen(pa[*i]->cmd[0])))
	{
		p = ft_split(pa[*i]->cmd[0], ' ');
		if (p == NULL)
			return (-1);
		k = nb_cmd(p);
		tmp = pa[*i]->cmdlst;
		pa[*i]->cmdlst = pa[*i]->cmdlst->next;
		free(tmp->content);
		free(tmp);
		while (--k, k >= 0)
		{
			ft_lstadd_front(&pa[*i]->cmdlst, ft_lstnew(ft_strdup(p[k]), NULL));
			if (pa[*i]->cmdlst->content == NULL)
				return (ft_free_split(p), -1);
		}
		if (list_to_cmd(pa, *i) == -1)
			return (ft_free_split(p), -1);
		else
			return (ft_free_split(p), 0);
	}
	return (0);
}
