/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:00:00 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/13 18:47:10 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_minishell *minishell, int argc, char **argv)
{
	int	i;

	(void)argc;
	(void)argv;
	if (!minishell->env_array || !*minishell->env_array)
		return (1);
	i = 0;
	while (minishell->env_array[i])
	{
		ft_putendl_fd(minishell->env_array[i], STDOUT_FILENO);
		++i;
	}
	return (0);
}
/*
int	main(int argc, char **argv, char ** envp)
{
	(void)argc;
	(void)argv;
	ft_env(envp);
	return (0);
}*/
