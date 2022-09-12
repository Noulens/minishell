/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:43:44 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/12 20:09:14 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *minishell, char *code)
{
	char	*p;

	p = code;
	clean_up(minishell->gb, minishell->env);
	ft_printf("exit\n");
	if (p == NULL)
		exit(minishell->exec_ret);
	else
	{
		while (*p)
		{
			if (!ft_isdigit(*p))
			{
				ft_printf("minishell: exit: %s: not numeric\n", code);
				exit(2);
			}
			p++;
		}
		exit(ft_atoi(code));
	}
}
