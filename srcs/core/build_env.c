/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:53:15 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/06 16:46:16 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_env_var(t_minishell *ms, int shlvl)
{
	char	*pwd;
	char	*lvl;

	pwd = getcwd(NULL, 0);
	lvl = ft_itoa(shlvl);
	ft_lstadd_back(&ms->env, ft_lstnew(ft_strjoin("SHLVL=", lvl), NULL));
	if (ft_lstlast(ms->env)->content == NULL)
		return (perror("init_env_var"), (void)0);
	free(lvl);
	ft_lstadd_back(&ms->env, ft_lstnew(ft_strjoin("PWD=", pwd), NULL));
	if (ft_lstlast(ms->env)->content == NULL)
		return (perror("init_env_var"), (void)0);
	free(pwd);
}

static void	check_shlvl(int *shlvl)
{
	if (*shlvl >= 1000)
	{
		ft_putendl_fd("Warning: shell level too high returning to 1", 2);
		*shlvl = 1;
	}
	else
		++*shlvl;
}

static void	normadjust(t_minishell *ms)
{
	bubblesortlist(ms->env);
	list_to_array(ms);
}

void	build_env(t_minishell *ms, char **envp)
{
	int	shlvl;
	int	i;

	shlvl = ft_atoi(getenv("SHLVL"));
	check_shlvl(&shlvl);
	init_env_var(ms, shlvl);
	i = 0;
	if (envp != NULL && *envp != NULL)
	{
		while (envp[i] != NULL)
		{
			if (!ft_strncmp(envp[i], "SHLVL=", 6)
				|| !ft_strncmp(envp[i], "PWD=", 4))
				i++;
			else
			{
				ft_lstadd_back(&ms->env, ft_lstnew(ft_strdup(envp[i]), NULL));
				if (!ft_lstlast(ms->env)
					|| !ft_lstlast(ms->env)->content)
					return (perror("build_env"), (void)0);
				i++;
			}
		}
	}
	normadjust(ms);
}
