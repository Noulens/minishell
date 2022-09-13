/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:44:09 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/12 23:33:50 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_clean_up(t_list *lst, char **env)
{
	strerror(errno);
	ft_lstclear(lst);
	ft_free_split(env);
	return ;
}

void	clean_up(t_list *lst, char **env)
{
	ft_lstclear(lst);
	ft_free_split(env);
	return ;
}
