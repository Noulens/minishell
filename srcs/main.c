/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:33:49 by tnoulens          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/08 13:54:38 by tnoulens         ###   ########.fr       */
=======
/*   Updated: 2022/09/08 17:12:57 by cfontain         ###   ########.fr       */
>>>>>>> 92ed35f82a12ff8b933296de5e4b0fdcfe882ed9
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*g_cm;

int	ft_strlen_tab(char **str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			i++;
		}
	}
	return (i);
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

static void	init_minishell(t_command *cm, int argc, char **argv, char **envp)
{
	g_cm = cm;
	cm->env = NULL;
	build_env(cm, envp);
}

int	main(int argc, char **argv, char **envp)
{
	char		*p;
	int		i;
	t_minishell minishell;
	t_command cm;

	i = 0;
	init_struct(&cm, envp, argc, argv);
	g_cm = &cm;
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
		p = parsing_alias(p, envp);
		minishell.cmd_array = m_split(p);
		parsing_token(minishell.cmd_array[i], &cm);
		cm.gb = ft_lstnew(NULL, (void **)minishell.cmd_array);
		if (cm.gb == NULL)
			return (ft_printf("%s", strerror(errno)), errno);
		gb_c(&cm.gb, (void *)p, NULL);
		minishell.nbr_cmd = ft_strlen_tab(minishell.cmd_array);
		cm.exec_ret = pipex(&cm);
		ft_lstclear(cm.gb);
		printf("%d\n", cm.exec_ret);
		init_struct(&cm, envp, argc, argv);
	}
	return (0);
}

/*int	main(int argc, char **argv, char **envp)
{
	char		*p;
	int		i;
	t_minishell minishell;

	i = 0;
	init_struct(&minishell.cm[0], envp, argc, argv);
	g_cm = &minishell.cm[0];
	print_welcome_msg();
	signal_handling();
	while (42)
	{
		p = prompt_line(&minishell.cm[0]);
		if (space_only(p))
		{
			minishell.cm[0].sigint = FALSE;
			continue ;
		}
		minishell.cmd_array = m_split(p);
		//minishell.cmd_array = ft_lstnew(NULL, (void **)cm.cmd);
		//if (minishell.cmd_array == NULL)
		//	return (ft_printf("%s", strerror(errno)), errno);
		minishell.nbr_cmd = ft_strlen_tab(minishell.cmd_array);
		while (i < minishell.nbr_cmd)
		{
			printf("%d\n", minishell.nbr_cmd);
			parsing_token(minishell.cmd_array[i], &minishell.cm[i]);	
			minishell.cm[i].exec_ret = pipex(&minishell.cm[i]);
			ft_lstclear(minishell.cm[i].gb);
			printf("%d\n", minishell.cm[i].exec_ret);
			init_struct(&minishell.cm[i], envp, argc, argv);
			i++;
		}	
	}
	return (0);
}*/