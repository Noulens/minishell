/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:34:17 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/20 13:01:04 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prompt_line(t_minishell *ms, t_command *cm)
{
	static char	*line_read;

	(void)cm;
	if (line_read)
	{
		free(line_read);
		line_read = NULL;
	}
	line_read = readline("> ");
	if (line_read == NULL)
	{
		clean_up(ms->gb, ms->env_array, ms->env);
		ft_printf("exit\n");
		exit(4);
	}
	if (*line_read == '\0')
		return (NULL);
	if (line_read && *line_read)
		add_history(line_read);
	if (g_ms->sigint == TRUE)
		g_ms->sigint = FALSE;
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
