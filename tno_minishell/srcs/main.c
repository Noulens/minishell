/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:33:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/26 15:23:32 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	space_only(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (isspace(p[i]))
			i++;
		else
			return (0);
	}
	return (1);
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
		if (p == NULL || space_only(p))
			continue ;
		cm.cmd = ft_split(p, '|');
		cm.exec_ret = pipex(&cm);
		ft_free_split(cm.cmd);
		ft_lstclear(*(cm.gb));
		printf("%d\n", cm.exec_ret);
	}
	free(p);
	return (0);
}
