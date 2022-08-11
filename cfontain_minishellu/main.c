/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:41:39 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/05 15:48:56 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_printab(char **str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			ft_printf("%s\n", str[i]);
			i++;
		}
	}
}


char *cut_return_line(t_command *command)
{
	int		i;
	char	*str;

	i = 0;
	str = calloc( 1, ft_strlen(command->name) + 1);
	if (str == NULL)
		return (perror("Malloc Failed"), NULL);
	while (command->name[i] != 0 && command->name[i] != '\n')
	{
		str[i] = command->name[i];
		i++;
	}
	free (command->name);
	return (str);
}

int	parse_arg(t_command *command, char **env)
{
	if (parse_command(command, env) == 1)
		return (1);
	return (0);
}


/* 	Si on veut une boucle il faut faire le execve dans un child car il met fin a la boucle
	parser les differents types d'arguments, entre les pipes les chevrons les commandes, les noms de fichier et les builtin
*/

int main(int argc, char **argv, char **env)
{
	
	t_minishell minishell;
	(void)argv;
	(void)argc;
	(void)env;
	init(&minishell);
	init_username(&minishell);
	ft_printf("%s:%s$ ", minishell.username, minishell.pathname);
	minishell.command.name = readline(0);
	while (minishell.command.name != NULL)
	{
		if (ft_builtin(&minishell) == 1)
		{
			if (parse_arg(&minishell.command, env) == 1)
				destroy_command(&minishell.command);
			ft_fork(&minishell.command, env);
		}	
		destroy_command(&minishell.command);
		ft_printf("%s:%s$ ", minishell.username, minishell.pathname);
		minishell.command.name = readline(0);
	}
	//ft_printf("%s", minishell.command.name);	
	
	return (destroy_all(&minishell), 0);
}



/*

- getcwd = recupere le chemin absolu du repertoire courant /mnt/nfs/homes/cfontain/Documents/Cursus/Minishellu

- chdir = permet de modifier le repertoire de travail courant au sein du processus
- stat = j'ai rien compris, ca recupere des stats sur un fichier, peut etre pour pouvoir verifier les droits d'acces dessus ou autre.
- unlink = detruit un nom ou fichier je crois, peut etre utile pour rm
- opendir = ouvre un "flux" repertoire, pas compris si ca permet de faire des mkdir ou pas

*/