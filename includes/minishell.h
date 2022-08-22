/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:50:14 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/22 17:00:01 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _POSIX_C_SOURCE 199309L
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <signal.h>
# include <linux/limits.h>
# include <limits.h>
# include <errno.h>
# include "../libft/libft.h"

/* define macros */

# define SA_RESTART	0x10000000
# define SUCCESS 0
# define FAIL 1
# define MAX_PIPE 1024 /* max # of pipe per process: pipe(7) man page
set in /proc/sys/fs/pipe-user-pages-soft (since Linux 4.5) */

/* Structure signal*/

typedef struct s_signal
{
	pid_t	pid_client;
}	t_signal;

typedef struct s_commands
{
	char	**cmd;
	char	**env;
	int		fd[2];
	t_list	**gb;
}	t_command;

/* Protos */

	/* --- core --- */

char	*prompt_line(void);
int		exec(char **argv, char **envp);

	/* --- utilities --- */

void	print_welcome_msg(void);
int		gb_c(t_list **gb, void *content, void **content2);

	/* --- build-in --- */

int		ft_echo(int argc, char **argv);
int		ft_pwd(void);
int		ft_env(char **envp);
void	ft_exit(t_list **gb);

/* This is a minimal set of ANSI/VT100 color codes */

# define END "\033[0m"
# define GREY "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define BLUE "\033[0;34m"
# define IRED "\033[0;41m"

#endif