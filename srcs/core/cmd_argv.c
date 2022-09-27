/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:51:33 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/27 18:01:03 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_argv(char **argv, t_minishell *minishell)
{
	char	*p;

	if (ft_strncmp(argv[0], "-c", 2) == 0)
		p = argv[1];
	else
		p = str_join_tab(argv);
	if (p == NULL)
		return (1);
	if (lexer_and_expend(p, minishell) == 1)
		return (ft_printf("%s", strerror(errno)), errno);
	minishell->exec_ret = parse(minishell);
	if (minishell->exec_ret != 1)
		minishell->exec_ret = pipex(minishell);
	ft_lstclear(minishell->gb);
	ft_lstclear_tok(minishell->list);
	printf("exit code: %d\n", minishell->exec_ret);
	free_param(minishell->cm);
	ft_lstclear(minishell->env);
	free(minishell->env_array);
	return (0);
}
