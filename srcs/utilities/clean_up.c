/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:44:09 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/13 20:23:11 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_clean_up(t_list *lst, char **env_array, t_list *env)
{
	strerror(errno);
	ft_lstclear(lst);
	ft_lstclear(env);
	free(env_array);
	return ;
}

void	clean_up(t_list *lst, char **env_array, t_list *env)
{
	ft_lstclear(lst);
	ft_lstclear(env);
	free(env_array);
	return ;
}
