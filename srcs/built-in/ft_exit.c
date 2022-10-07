/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:43:44 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/07 19:14:41 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_fd(void)
{
	if (close(0) == -1)
		return (perror("exit close"), (void)0);
	if (close(1) == -1)
		return (perror("exit close"), (void)0);
	if (close(2) == -1)
		return (perror("exit close"), (void)0);
}

static void	wrap_up_exit(t_minishell *minishell)
{
	ft_lstclear_tok(minishell->list);
	free_param(minishell->cm);
	clean_up(minishell->gb, minishell->env_array, minishell->env);
	exit_fd();
}

static void	exit_1(t_minishell *minishell)
{
	ft_lstclear_tok(minishell->list);
	free_param(minishell->cm);
	clean_up(minishell->gb, minishell->env_array, minishell->env);
	ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	exit_fd();
	exit(1);
}

static void	exit_args(char **argv, t_minishell *minishell)
{
	char		*p;
	long long	code;

	p = argv[1];
	if (*p == '-')
		p++;
	while (*p)
	{
		if (!ft_isdigit(*p))
		{
			ft_putstr_fd("minishell: exit: not a numeric argument\n", 2);
			wrap_up_exit(minishell);
			exit(2);
		}
		p++;
	}
	code = ft_capped_atoll(argv[1]);
	if (code == 0 && ft_strlen(argv[1]) > 1)
	{
		ft_putstr_fd("minishell: exit: not a numeric argument\n", 2);
		wrap_up_exit(minishell);
		exit(2);
	}
	wrap_up_exit(minishell);
	exit((unsigned char)code);
}

int	ft_exit(t_minishell *minishell, int argc, char **argv)
{
	if (isatty(0) && isatty(2))
		ft_fprintf(2, "exit\n");
	if (argc == 1)
	{
		wrap_up_exit(minishell);
		exit(minishell->exec_ret);
	}
	else if (argc > 2)
		exit_1(minishell);
	else
		exit_args(argv, minishell);
	return (SUCCESS);
}
