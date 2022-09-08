/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:53:15 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/08 16:45:29 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	nb_var(char **envp)
{
	int	i;

	i = 0;
	while (*envp++)
		i++;
	return (i);
}

void	build_env(t_command *cm, char **envp)
{
	int		shlvl;
	char	*pwd;
	char	*env_shlvl;
	char	*p;
	int		i;

	i = nb_var(envp);
	env_shlvl = getenv("SHLVL");
	shlvl = ft_atoi(env_shlvl);
	if (!env_shlvl)
		i++;
	pwd = getenv("PWD")
	if (!pwd)
		i++;
	p = getenv("_")
	if (!p)
		i++;
	cm->env = (char **)malloc(sizeof(char *) * i + sizeof(char *));
	if (cm->env == NULL)
		return (strerror(errno), NULL);
		
}
