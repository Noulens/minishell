/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:35:15 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/23 16:47:36 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	gb_c(t_list **gb, void *content, void **content2)
{
	ft_lstadd_back(gb, ft_lstnew(content, content2));
	if (!(*gb)->content && !(*gb)->content2)
		return (-1);
	else
		return (0);
}
