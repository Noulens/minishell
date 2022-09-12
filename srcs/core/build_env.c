/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:53:15 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/09 17:28:34 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	nb_var(char **envp)
{
	int		i;
	char	**p;

	i = 0;
	p = envp;
	if (p != NULL && *p != NULL)
	{
		while (*p++)
			i++;
	}
	if (!getenv("SHLVL"))
		i++;
	if (!getenv("PWD"))
		i++;
	return (i);
}

static void	init_env_var(t_minishell *ms, int i, int shlvl)
{
	char	*pwd;
	char	*lvl;

	pwd = getcwd(NULL, 0);
	lvl = ft_itoa(shlvl);
	ms->env = (char **)malloc(sizeof(char *) * i + sizeof(char *));
	if (ms->env == NULL)
	{
		perror("init_env_var");
		exit(errno);
	}
	ms->env[0] = ft_strjoin("SHLVL=", lvl);
	free(lvl);
	ms->env[1] = ft_strjoin("PWD=", pwd);
	free(pwd);
	ms->env[i] = NULL;
}

void	build_env(t_minishell *ms, char **envp)
{
	int	shlvl;
	int	i;
	int	j;

	i = nb_var(envp);
	shlvl = ft_atoi(getenv("SHLVL"));
	++shlvl;
	init_env_var(ms, i, shlvl);
	i = 0;
	j = 0;
	if (envp != NULL && *envp != NULL)
	{
		while (envp[i] != NULL)
		{
			if (!ft_strncmp(envp[i], "SHLVL=", 6)
				|| !ft_strncmp(envp[i], "PWD=", 4))
				i++;
			else
			{
				ms->env[j + 2] = ft_strdup(envp[i]);
				j++;
				i++;
			}
		}
	}
}
/*
void	ft_printab(char **str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			ft_printf("%s\n", str[i]);
			i++;
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	ms;

	(void)argc;
	(void)argv;
	build_env(&ms, envp);
	ft_printab(ms.env);
	ft_free_split(ms.env);
	return (0);
}*/
