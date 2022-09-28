/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:34:17 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/28 21:39:50 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prompt_line(t_minishell *ms)
{
	static char	*line_read;

	if (line_read)
	{
		free(line_read);
		line_read = NULL;
	}
	line_read = readline("Minishell $> ");
	if (line_read == NULL)
	{
		clean_up(ms->gb, ms->env_array, ms->env);
		ft_printf("exit\n");
		exit_fd();
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
