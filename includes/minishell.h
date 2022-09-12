/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:50:14 by tnoulens          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/12 14:35:10 by cfontain         ###   ########.fr       */
=======
/*   Updated: 2022/09/09 17:58:36 by tnoulens         ###   ########.fr       */
>>>>>>> 028d83a75eff617d6a570501db96db6e715f6eeb
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
# define TRUE 1
# define FALSE 0
# define MAX_PIPE 1024 /* max # of pipe per process: pipe(7) man page
set in /proc/sys/fs/pipe-user-pages-soft (since Linux 4.5) */

/* Structure signal*/

typedef struct s_list_split
{
	char			*str;
	void	*next;
}	t_list_split;

typedef struct s_new_cut_line
{
	int		i;
	int		j;
	int		trigger;
	char	c;

}			t_new_cut_line;

typedef struct s_mega_split
{
	int		i;
	int		j;
	int		count;

}			t_mega_split;

typedef struct s_split
{
	char	**str;
	int		len;
	int		count;
}	t_split;

typedef struct s_signal
{
	pid_t	pid_client;
}	t_signal;

typedef struct s_commands
{
	char	**cmd;
	char	*infile;
	char	*outfile;
	char	**env;
	pid_t	pid;
	pid_t	*pids;
	int		*end;
	int		fd[2];
	int		fdhd;
	short	here_doc;
	short	outfile_append;
	char	*limiter;
	int		exec_ret;
	short	sigint;
	
}	t_command;

typedef struct s_minishell
{
<<<<<<< HEAD
	t_command cm[10];
	int	nbr_cmd;
	char	**cmd_array;
	int		exec_ret;
	t_list	*gb;
=======
	t_command	cm[10];
	char		**env;
	int			nbr_cmd;
	char		**cmd_array;
>>>>>>> 028d83a75eff617d6a570501db96db6e715f6eeb
}	t_minishell;
/* Protos */

	/* --- parsing line --- */


void	ft_printab(char **str);
int		char_is_whitespace(char c);
char	*init_str_alias(char *str, char **env, int len, t_minishell *minishell);
int		break_point_alias(char *str, int i);
int		trigger_double_quote(int trigg, char c);
int		init_cmd(char *str, t_command *cmd, t_minishell *minishell);
char	*m_init_str(char *s, char c, char *str, int *j);
int		m_line_lenght(char *s, char c, int *j);
char	**ft_split_space_and_quote(char *s, char c);
char	**m_split(char *str);
void	count_sep_quote(t_mega_split *split, char *s);
int		m_split_count_line(char *s, char c);
void	ft_count_up(t_mega_split *split);
char	*m_malloc_str(char *str, int len);
void	m_init_str_with_sep(char *s, char *str, int *i, int *k);
<<<<<<< HEAD
=======
int		char_is_quote(char c);
>>>>>>> 028d83a75eff617d6a570501db96db6e715f6eeb
int		check_single_quote(char *str, int *i);
int		check_double_quote(char *str, int *i);
int		parsing_quote(char *str);
void	new_cut_line2(char *str, char *new_str, t_new_cut_line *line);
char	*new_cut_line(char *str);
int		cut_quote(char **split_line);
char	*expend_alias(char *str, char **env, t_minishell *minishell);
	/* --- core --- */

char	*prompt_line(t_command *cm);
int		exec(char **argv, char **envp);
<<<<<<< HEAD
int		pipex(t_command *cm, t_minishell *minishell);
=======
int		pipex(t_command *cm);
void	build_env(t_minishell *ms, char **envp);
>>>>>>> 028d83a75eff617d6a570501db96db6e715f6eeb

	/* --- utilities --- */

void	print_welcome_msg(void);
int		gb_c(t_list **gb, void *content, void **content2);
<<<<<<< HEAD
void	init_struct(t_command *cm, char **envp);
void	init_minishell(t_minishell *minishell);
=======
void	clean_up(t_list *lst, char **env);
void	init_struct(t_minishell *ms, t_command *cm);
>>>>>>> 028d83a75eff617d6a570501db96db6e715f6eeb
int		close_pipes(int cmd_nbr, int *end, t_command *cm);
void	close_std_in_child(void);
int		open_pipes(int cmd_nbr, int *end);
void	dupper(int input, int output);
int		char_is_token(char c);
int		char_is_quote(char c);
int		char_is_whitespace(char c);
int		check_quote(char *str, int i);

	/* --- build-in --- */

int		ft_echo(int argc, char **argv);
int		ft_pwd(void);
int		ft_env(char **envp);
void	ft_exit(t_minishell *minishell);

	/* --- signals --- */
void	tmp_handler(int sig, siginfo_t *info, void *context);
void	signal_handling(void);

extern t_command	*g_cm;

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