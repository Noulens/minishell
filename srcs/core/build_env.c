/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:53:15 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/16 10:38:16 by cfontain         ###   ########.fr       */
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

void	list_to_array(t_minishell *ms)
{
	t_list	*tmp;
	size_t	idx;

	if (ms->env_array != NULL)
		free(ms->env_array);
	idx = ft_lstsize(ms->env);
	ms->env_array = (char **)ft_calloc(sizeof(char *), idx + 1);
	if (!ms->env_array)
		return (perror("list_to_array"), (void)0);
	tmp = ms->env;
	idx = 0;
	while (tmp != NULL)
	{
		ms->env_array[idx] = tmp->content;
		idx++;
		tmp = tmp->next;
	}
}

void	build_env(t_minishell *ms, char **envp)
{
	int	shlvl;
	int	i;

	shlvl = ft_atoi(getenv("SHLVL"));
	++shlvl;
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
				if (ft_lstlast(ms->env)->content == NULL)
					return (perror("build_env"), (void)0);
				i++;
			}
		}
	}
	list_to_array(ms);
}
/*
void	ft_printlist(t_list *list)
{
	if (list)
	{
		while (list != NULL)
		{
			if (list->content != NULL)
				ft_printf("%s\n", list->content);
			list = list->next;
		}
	}
}

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

void	ftft_lstclear(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		if (lst->content)
		{
			ft_printf("%s\n", lst->content);
			free(lst->content);
		}
		if (lst->content2 != NULL)
			ft_free_split((char **)lst->content2);
		free(lst);
		lst = tmp;
	}
	lst = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	ms;

	(void)argc;
	(void)argv;
	ms.env = NULL;
	build_env(&ms, envp);
	ft_printlist(ms.env);
	ft_printf("\n");
	ft_printab(ms.env_array);
	ft_printf("\n");
	ftft_lstclear(ms.env);
	free(ms.env_array);
	return (0);
}*/
