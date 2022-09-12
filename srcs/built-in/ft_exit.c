/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:43:44 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/12 13:18:19 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *minishell)
{
	ft_lstclear(minishell->gb);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
