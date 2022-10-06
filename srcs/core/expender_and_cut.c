/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_and_cut.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:50:36 by cfontain          #+#    #+#             */
/*   Updated: 2022/10/06 12:43:45 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expender(char *str, t_minishell *ms)
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
	len = count_expender(i, str, ms);
	len += ft_strlen(str);
	new_str = init_expender(str, len, ms);
	if (new_str == NULL)
		return (NULL);
	return (new_str);
}

int	expender_and_cut(t_minishell *minishell)
{
	char	*str;
	t_tok	*temp;

	temp = minishell->list;
	while (minishell->list)
	{
		str = expender(minishell->list->data, minishell);
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
