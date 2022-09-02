/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:33:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/02 11:28:52 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	char		*p;
	t_command	cm;
	t_list		*list;
	(void)argc;
	(void)argv;
	list = NULL;
	cm.env = envp;
	cm.gb = &list;
	print_welcome_msg();
	while (42)
	{
		p = prompt_line();
		parsing_token(p);
		cm.cmd = ft_split(p, '|');
		pipex(&cm);
		ft_free_split(cm.cmd);
		printf("%d\n", cm.exec_ret);
	}
	ft_lstclear(*(cm.gb));
	free(p);
	return (0);
}
