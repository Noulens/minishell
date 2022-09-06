/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:33:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/06 16:50:15 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*g_cm;

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

int	space_only(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (ft_isspace(p[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	build_env(t_command *cm, char **envp)
{
	char	shlvl[10];
	char	*p;
	
	if (envp != NULL)
	{
		cm->env = ft_lstnew(*envp, NULL);
		cm->env++;
	}
	p = getenv("SHLVL");
	if (!p)
		;
	while (*envp != NULL)
	{
		ft_lstadd_back(&cm->env, ft_lstnew(*envp, NULL));
		*envp++;
	}
}

void	init_minishell(t_command *cm, int argc, char **argv, char **envp)
{
	init_struct(cm, envp, argc, argv);
	g_cm = cm;
	cm->env = NULL;
	build_env(cm, envp);
}

int	main(int argc, char **argv, char **envp)
{
	char		*p;
	t_command	cm;

	print_welcome_msg();
	signal_handling();
	init_minishell(&cm, envp, argc, argv);
	while (42)
	{
		p = prompt_line(&cm);
		if (space_only(p))
		{
			cm.sigint = FALSE;
			continue ;
		}
		cm.cmd = ft_split(p, '|');
		cm.gb = ft_lstnew(NULL, (void **)cm.cmd);
		if (cm.gb == NULL)
			return (ft_printf("%s", strerror(errno)), errno);
		cm.exec_ret = pipex(&cm);
		ft_lstclear(cm.gb);
		printf("%d\n", cm.exec_ret);
		init_struct(&cm, envp, argc, argv);
	}
	return (0);
}
