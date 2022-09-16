/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:09:29 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/16 00:36:33 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

# define END_LEX 0
# define STDIN_LEX 1
# define STDOUT_LEX 2
# define HEREDOC_LEX 3
# define APPEND_LEX 4
# define CMD_LEX 5
# define PIPE_LEX 6

/* EXPAND A FIXER, CA DOIT FAIRE CA:
waxxy@waxxy-VirtualBox:~/Desktop/minishell$ echo $?
0
waxxy@waxxy-VirtualBox:~/Desktop/minishell$ echo "'$?'"
'0'
waxxy@waxxy-VirtualBox:~/Desktop/minishell$ echo '"$?"'
"$?"
waxxy@waxxy-VirtualBox:~/Desktop/minishell$ 
*/

int	countcmd(t_tok *tok)
{
	int		k;
	t_tok	*tmk;

	tmk = tok;
	k = 0;
	while (tmk)
	{
		if (tmk->type = 6 && tmk->next->type != 6 && tmk->next->type != 0)
			k++;
	}
}

int	parse(t_minishell *ms)
{
	t_tok	*tmp;
	int		i;

	i = 0;
	
}
