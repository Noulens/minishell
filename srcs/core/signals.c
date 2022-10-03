/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:33:49 by waxxy             #+#    #+#             */
/*   Updated: 2022/10/03 18:54:45 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tmp_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGINT)
	{
		g_ms->sigint = TRUE;
		g_ms->exec_ret = 130;
		if (g_ms->i.i != -1)
		{
			if (close(g_ms->cm[g_ms->i.i]->fdhd) == -1)
				perror("tmp_handler close");
			unlink(".here_doc.tmp");
		}
		write(STDIN_FILENO, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT)
		ft_printf("\b\b");
	if (sig == SIGTERM)
		ft_printf("\b\b");
}

void	signal_handling(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = tmp_handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);
}
