/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:50:10 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/15 17:01:21 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int find_idx(t_list *lst, char *arg)
{
	int i;
	t_list *p;

	i = 0;
	p = lst;
	while (p)
	{
		if (ft_cmpchr(p->content, arg, '=') == 0)
			return (i);
		p = p->next;
		i++;
	}
	return (-1);
}

static void	del_idx_0(t_minishell *ms)
{
	t_list	*tmp;
	
	tmp = ms->env;
	ms->env = ms->env->next;
	free(tmp->content);
	free(tmp);
}

static void	del_idx_pos(t_minishell *ms, int idx)
{
	t_list	*tmp;
	t_list	*tmp2;
	
	tmp2 = ms->env;
	while (idx--)
	{
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	tmp->next = tmp2->next;
	free(tmp2->content);
	free(tmp2);
}

int ft_unset(t_minishell *ms, int argc, char **argv)
{
	int		i;
	int		idx;

	if (argc == 1)
		return (SUCCESS);
	i = 1;
	while (argv[i] != NULL)
	{
		idx = find_idx(ms->env, argv[i]);
		if (idx == 0)
			del_idx_0(ms);
		else if (idx > 0)
			del_idx_pos(ms, idx);
		i++;
	}
	list_to_array(ms);
	return (SUCCESS);
}

////////******* DEBUT TEST ********////////
/*
static void init_env_var(t_minishell *ms, int shlvl)
{
	char *pwd;
	char *lvl;

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

void list_to_array(t_minishell *ms)
{
	t_list *tmp;
	size_t idx;

	if (ms->env_array != NULL)
		free(ms->env_array);
	idx = ft_lstsize(ms->env);
	ft_printf("%d\n", idx);
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

void build_env(t_minishell *ms, char **envp)
{
	int shlvl;
	int i;

	shlvl = ft_atoi(getenv("SHLVL"));
	++shlvl;
	init_env_var(ms, shlvl);
	i = 0;
	if (envp != NULL && *envp != NULL)
	{
		while (envp[i] != NULL)
		{
			if (!ft_strncmp(envp[i], "SHLVL=", 6) || !ft_strncmp(envp[i], "PWD=", 4))
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

void ft_printlist(t_list *list)
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

void ft_printab(char **str)
{
	int i;

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

void ftft_lstclear(t_list *lst)
{
	t_list *tmp;

	if (!lst)
		return;
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

static void exportlist(t_list *list)
{
	if (list)
	{
		while (list != NULL)
		{
			if (list->content != NULL)
			{
				ft_printf("declare -x ");
				ft_printf("%s\n", list->content);
			}
			list = list->next;
		}
	}
}

int	str_is_alnum(char *p)
{
	char	*ptr;

	ptr = p;
	if (!ft_isalpha(*ptr))
		return (1);
	ptr++;
	while (*ptr && *ptr != '=')
	{
		if (ft_isalnum(*ptr))
			ptr++;
		else
			return (1);
	}
	return (0);
}

int	formatok(char *str)
{
	char	*p;

	p = ft_strchr(str, '=');
	if (p == NULL || *p == *str || str_is_alnum(str))
	{
		ft_putstr_fd("export: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": no export done, not a valid identifier\n", 2);
		return (1);
	}
	else
		return (0);
}

int	is_in_env(t_list *lst, char *str)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!ft_cmpchr(str, tmp->content, '='))
		{
			free(tmp->content);
			tmp->content = ft_strdup(str);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int ft_export(t_minishell *minishell, int argc, char **argv)
{
	int 	i;

	if (argc == 1)
		exportlist(minishell->env);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!formatok(argv[i]) && !is_in_env(minishell->env, argv[i]))
			{
				ft_lstadd_back(&minishell->env,
					ft_lstnew(ft_strdup(argv[i]), NULL));
				if (ft_lstlast(minishell->env)->content == NULL)
					return (perror("ft_export"), errno);
			}
			++i;
		}
		list_to_array(minishell);
	}
	return (SUCCESS);
}

int main(int argc, char **argv, char **envp)
{
	t_minishell ms;

	argc;
	argv;
	ms.env = NULL;
	ft_printf("\n");
	ft_printf(BOLD);
	ft_printf(YELLOW"\n");
	ft_printf("BUILD ENV");
	ft_printf("\n"END);
	build_env(&ms, envp);
	ft_printlist(ms.env);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf(BOLD);
	ft_printf(YELLOW"\n");
	ft_printf("LST TO ARRAY");
	ft_printf("\n"END);
	ft_printab(ms.env_array);
	ft_printf("\n");
	ft_printf(BOLD);
	ft_printf(YELLOW"\n");
	ft_printf("DEBUT TEST EXPORT");
	ft_printf("\n"END);
	ft_export(&ms, argc, argv);
	ft_printf("\n");
	ft_printlist(ms.env);
	ft_printf("\n");
	ft_printf(BOLD);
	ft_printf(YELLOW"\n");
	ft_printf("LST TO ARRAY AFTER EXPORT");
	ft_printf("\n"END);
	ft_printab(ms.env_array);
	ft_printf("\n");
	ft_printf(BOLD);
	ft_printf(YELLOW"\n");
	ft_printf("DEBUT TEST UNSET");
	ft_printf("\n"END);
	ft_unset(&ms, argc, argv);
	ft_printlist(ms.env);
	ft_printf("\n");
	ft_printf(BOLD);
	ft_printf(YELLOW"\n");
	ft_printf("LST TO ARRAY");
	ft_printf("\n"END);
	ft_printab(ms.env_array);
	ft_printf("\n");
	ft_printf(BOLD);
	ft_printf(YELLOW"\n");
	ft_printf("LST CLEAR");
	ft_printf("\n"END);
	ftft_lstclear(ms.env);
	free(ms.env_array);
	return (0);
}*/
