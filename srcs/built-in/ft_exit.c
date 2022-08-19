/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:43:44 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/19 20:06:55 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(t_list **gb)
{
	/* mettre fct qui detruit le gqrbqge collector */
	rl_clear_history();
	prinft("exit");
	exit(EXIT_SUCCESS);
}