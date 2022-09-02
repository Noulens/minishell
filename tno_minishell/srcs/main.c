/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:33:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/02 13:49:13 by waxxy            ###   ########.fr       */
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

	(void)argc;
	(void)argv;
	cm.env = envp;
	cm.exec_ret = -1;
	cm.gb = NULL;
	//print_welcome_msg();
	while (42)
	{
		p = prompt_line();
		if (p == NULL || space_only(p))
			continue ;
		cm.cmd = ft_split(p, '|');
		cm.gb = ft_lstnew(NULL, (void **)cm.cmd);
		if (cm.gb == NULL)
			return (-2);
		cm.exec_ret = pipex(&cm);
		ft_lstclear(cm.gb);
		printf("%d\n", cm.exec_ret);
	}
	free(p);
	return (0);
}
