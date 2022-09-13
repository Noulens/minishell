/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:43:44 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/13 20:03:55 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_1(void)
{
	ft_putstr_fd("minishell: exit: too many arguments", 2);
	exit(1);
}

static void	exit_args(char **argv)
{
	char *p;
	
	p = *argv + 1;
	while (*p)
	{
		if (!ft_isdigit(*p))
		{
			ft_putstr_fd("minishell: exit:", 2);
			ft_putstr_fd(*argv + 1, 2);
			ft_putstr_fd(": not a numeric argument\n", 2);
			exit(2);
		}
		else
			p++;
	}
	exit(ft_atoi(*argv + 1));
}

void	ft_exit(t_minishell *minishell, int argc, char **argv)
{
	(void)argc;
	clean_up(minishell->gb, minishell->env_array, minishell->env);
	ft_printf("exit\n");
	if (argc == 1)
		exit(minishell->exec_ret);
	else if (argc > 2)
		exit_1();
	else
		exit_args(argv);
}
