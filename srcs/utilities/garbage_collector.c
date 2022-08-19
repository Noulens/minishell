/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:35:15 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/19 18:41:32 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	gb_c(t_list **gb, void *content)
{
	ft_lstadd_back(gb, ft_lstnew(content));
	if (!ft_lstlast(*gb)->content)
		return (-1);
	else
		return (0);
}
