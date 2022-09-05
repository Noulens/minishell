/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:00:00 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/05 16:36:11 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **envp)
{
	int	i;

	if (!envp || !*envp)
		return (1);
	i = 0;
	while (envp[i])
	{
		ft_putendl_fd(envp[i], 1);
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
