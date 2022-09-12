/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:33:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/12 15:51:45 by cfontain         ###   ########.fr       */
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
	if (p)
	{
		while (p[i])
		{
			if (isspace(p[i]))
				i++;
			else
				return (0);
		}
	}	
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char		*p;
	int		i;
	t_minishell minishell;
	t_command cm;

	i = 0;
	(void)argv;
	(void)argc;
	init_minishell(&minishell);
	g_cm = &cm;
	print_welcome_msg();
	signal_handling();
	while (42)
	{
		init_struct(&cm, envp);
		p = prompt_line(&cm);
		if (space_only(p))
		{
			cm.sigint = FALSE;
			continue ;
		}
		p = expend_alias(p, envp, &minishell);
		minishell.cmd_array = m_split(p);
		if (minishell.cmd_array == NULL)
			continue ;
		init_cmd(minishell.cmd_array[i], &cm, &minishell);
		minishell.gb = ft_lstnew(NULL, (void **)minishell.cmd_array); //TOUTES LES FONCTIONS QUI ECHOUE DOIVENT INFLUER SUR MINISHELL.EXEC_RET
		if (minishell.gb == NULL)
			return (ft_printf("%s", strerror(errno)), errno);
		gb_c(&minishell.gb, (void *)p, NULL);
		minishell.nbr_cmd = ft_strlen_tab(minishell.cmd_array);
		minishell.exec_ret = pipex(&cm, &minishell);
		ft_lstclear(minishell.gb);
		printf("%d\n", cm.exec_ret);
		//init_struct(&cm, envp);
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