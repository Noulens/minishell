/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:33:49 by waxxy             #+#    #+#             */
/*   Updated: 2022/10/12 16:09:49 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wrap_up_terminate(siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	ft_lstclear_tok(g_ms->list);
	free_param(g_ms->cm);
	clean_up(g_ms->gb, g_ms->env_array, g_ms->env);
	ft_fprintf(2, "\nTerminated\n");
	exit_fd();
	exit(143);
}

void	tmp_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGINT)
	{
		g_ms->sigint = TRUE;
		g_ms->exec_ret = 130;
		if (g_ms->i.l != -1)
		{
			if (close(g_ms->cm[g_ms->i.l]->fdhd) == -1)
				perror("tmp_handler close");
			unlink(".here_doc.tmp");
		}
		if (g_ms->pid == 0)
		{
			rl_replace_line("", 1);
			rl_on_new_line();
			write(2, "\n", 1);
			rl_redisplay();
		}
		else
			write(2, "", 1);
	}
	if (sig == SIGQUIT)
		ft_printf("\b\b");
	if (sig == SIGTERM)
		return (wrap_up_terminate(info, context), (void)0);
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
