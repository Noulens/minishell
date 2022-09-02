/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:35:15 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/02 14:00:11 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	gb_c(t_list **gb, void *content, void **content2)
{
	ft_lstadd_back(gb, ft_lstnew(content, content2));
	if (!(*gb)->content && !(*gb)->content2)
		return (-1);
	else
		return (0);
}
