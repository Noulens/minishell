/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:41:40 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/15 16:46:59 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear_tok(t_tok *lst)
{
	t_tok	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		if (lst->data)
			free(lst->data);
		free(lst);
		lst = tmp;
	}
	lst = NULL;
}

t_tok	*ft_lstlast_tok(t_tok *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_tok(t_tok **lst, t_tok *new)
{
	t_tok	*pl;

	if (lst)
	{
		if (*lst)
		{
			pl = ft_lstlast_tok(*lst);
			pl->next = new;
		}
		else
			*lst = new;
	}
}

t_tok	*ft_lstnew_tok(char *content, int content2)
{
	t_tok	*first;

	first = (t_tok *)malloc(sizeof(t_tok));
	if (!first)
		return (NULL);
	first->data = content;
	first->type = content2;
	first->next = NULL;
	return (first);
}
