/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:43:44 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/27 16:29:05 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_1(t_minishell *minishell)
{
	ft_lstclear_tok(minishell->list);
	free_param(minishell->cm);
	clean_up(minishell->gb, minishell->env_array, minishell->env);
	ft_putstr_fd(RED"minishell: exit: too many arguments\n"END, 2);
	exit(1);
}

static void	exit_args(char **argv, t_minishell *minishell)
{
	char	*p;
	int		len;
	long	code;

	p = argv[1];
	len = ft_strlen(p);
	while (*p)
	{
		if (!ft_isdigit(*p) || len > 20)
		{
			ft_putstr_fd(RED"minishell: exit:", 2);
			ft_putstr_fd(argv[1], 2);
			ft_putstr_fd(": not a numeric argument\n"END, 2);
			ft_lstclear_tok(minishell->list);
			free_param(minishell->cm);
			clean_up(minishell->gb, minishell->env_array, minishell->env);
			exit(2);
		}
		p++;
	}
	code = (unsigned char)ft_atol(argv[1]);
	ft_lstclear_tok(minishell->list);
	free_param(minishell->cm);
	clean_up(minishell->gb, minishell->env_array, minishell->env);
	exit(code);
}

int	ft_exit(t_minishell *minishell, int argc, char **argv)
{
	(void)argc;
	ft_printf(CYAN"exit bye !\n"END);
	if (argc == 1)
	{
		ft_lstclear_tok(minishell->list);
		free_param(minishell->cm);
		clean_up(minishell->gb, minishell->env_array, minishell->env);
		exit(minishell->exec_ret);
	}
	else if (argc > 2)
		exit_1(minishell);
	else
		exit_args(argv, minishell);
	return (SUCCESS);
}
