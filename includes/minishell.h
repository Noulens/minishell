/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:50:14 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/20 16:37:53 by waxxy            ###   ########.fr       */
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

/* Structure signal*/

typedef struct s_signal
{
	pid_t	pid_client;
}	t_signal;

/* Protos */

	/* --- core --- */

char	*prompt_line(void);

	/* --- utilities --- */

void	print_welcome_msg(void);
int		gb_c(t_list **gb, void *content);

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