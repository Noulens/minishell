/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:51:33 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/28 11:09:21 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_argv(char **argv, t_minishell *minishell)
{
	char	*p;

	if (ft_strncmp(argv[0], "-c", 2) == 0)
		p = argv[1];
	else
		p = str_join_tab(argv);
	if (p == NULL)
		return (perror("cmd mode: join"), error_clean_up(minishell), (void)0);
	if (lexer_and_expend(p, minishell) == 1)
		return (perror("cmd mode: lexer"), error_clean_up(minishell), (void)0);
	minishell->exec_ret = parse(minishell);
	if (minishell->exec_ret != 1)
		minishell->exec_ret = pipex(minishell);
	ft_lstclear(minishell->gb);
	ft_lstclear_tok(minishell->list);
	printf("exit code: %d\n", minishell->exec_ret);
	free_param(minishell->cm);
	ft_lstclear(minishell->env);
	free(minishell->env_array);
	exit(minishell->exec_ret);
}
