/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:43:44 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/27 21:56:24 by waxxy            ###   ########.fr       */
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

static void	exit_1(t_minishell *minishell)
{
	ft_lstclear_tok(minishell->list);
	free_param(minishell->cm);
	clean_up(minishell->gb, minishell->env_array, minishell->env);
	ft_putstr_fd(RED"minishell: exit: too many arguments\n"END, 2);
	exit_fd();
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
			ft_putstr_fd(RED"minishell: exit: not a numeric argument\n"END, 2);
			ft_lstclear_tok(minishell->list);
			free_param(minishell->cm);
			clean_up(minishell->gb, minishell->env_array, minishell->env);
			exit_fd();
			exit(2);
		}
		p++;
	}
	code = (unsigned char)ft_atol(argv[1]);
	ft_lstclear_tok(minishell->list);
	free_param(minishell->cm);
	clean_up(minishell->gb, minishell->env_array, minishell->env);
	exit_fd();
	exit(code);
}

int	ft_exit(t_minishell *minishell, int argc, char **argv)
{
	(void)argc;
	ft_printf("exit\n");
	if (argc == 1)
	{
		ft_lstclear_tok(minishell->list);
		free_param(minishell->cm);
		clean_up(minishell->gb, minishell->env_array, minishell->env);
		exit_fd();
		exit(minishell->exec_ret);
	}
	else if (argc > 2)
		exit_1(minishell);
	else
		exit_args(argv, minishell);
	return (SUCCESS);
}
