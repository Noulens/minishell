/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:34:17 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/05 16:35:47 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prompt_line(void)
{
	static char	*line_read;

	if (line_read)
	{
		free(line_read);
		line_read = NULL;
	}
	line_read = readline("> ");
	if (line_read && *line_read)
		add_history(line_read);
	else if (line_read == NULL)
	{
		ft_printf("exit\n");
		exit(4);
	}
	return (line_read);
}
/*
int main(int argc, char **argv, char **envp)
{
	char 		*p;
	t_command 	cm;
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
		cm.cmd = ft_split(p, '|');
		pipex(&cm);
		printf("ok\n");
	}
	ft_lstclear(*(cm.gb));
	free(p);
	return (0);
}*/
