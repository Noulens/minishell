/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:33:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/25 21:02:58 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*g_ms;

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
	char	*char_ptr;

	char_ptr = p;
	if (char_ptr != NULL)
	{
		while (char_ptr)
		{
			if (ft_isspace(*char_ptr))
				char_ptr++;
			else
				return (0);
		}
		return (1);
	}
	else
		return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char		*p;
	t_minishell	minishell;
	t_command	cm;
	
	init_minishell(&minishell);
	build_env(&minishell, envp);
	g_ms = &minishell;
	print_welcome_msg();
	signal_handling();
	if (argc > 1)
	{
		cmd_argv(argv + 1, &minishell);
		if (parse(&minishell) == 1)
			return (errno);
		minishell.exec_ret = pipex(&minishell);
		return (0);
	}	
	while (42)
	{
		minishell.nbr_cmd = 1;
		minishell.list = NULL;
		init_struct(&minishell, &cm);
		minishell.gb = NULL;
		p = prompt_line(&minishell);
		if (space_only(p))
		{
			cm.sigint = FALSE;
			continue ;
		}
		if (lexer_and_expend(p, &minishell) == 1)
			return (ft_printf("%s", strerror(errno)), errno);
		if (parse(&minishell) == 4)
			return (errno);
		minishell.exec_ret = pipex(&minishell);
		ft_lstclear(minishell.gb);
		ft_lstclear_tok(minishell.list);
		printf("exit code: %d\n", minishell.exec_ret);
		free_param(minishell.cm);
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





int main()
{
    char str[] = ">>";
    
    if (str[0] = (str[0] | str[1]))
        printf("ca marche\n");

    return 0;
}


0 = COMMANDE
1 = CHEVRON in
2 = CHEVRON OUT
3 = pipe
4 = alias ($)
5 = 0


}*/