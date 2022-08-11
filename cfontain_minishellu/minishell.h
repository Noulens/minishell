/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:10:43 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/05 15:49:49 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef struct s_command
{
	char *name;
	char **argv;
	char *path;
	char **split_path;

}			t_command;


typedef struct s_minishell
{
	t_command command;
	char *username;
	char *pathname;
}			t_minishell;

char	*str_triple_join(char *s1, char *s2);
char	*ft_check_path(char **path, t_command *command);
char	**return_env(char *str);
char	*return_path(char **env);

void	init(t_minishell *minishell);
void	init_command(t_command *command);

void	ft_printab(char **str);

void	destroy_all(t_minishell *minishell);
void	destroy_command(t_command *command);

int		parse_command(t_command *command, char **env);
int		parse_absolute_path(t_command *command);

void    init_username(t_minishell *minishell);
int		ft_fork(t_command *command, char **env);
int		ft_child1(t_command *command, char **env);

int ft_builtin(t_minishell *minishell);
#endif