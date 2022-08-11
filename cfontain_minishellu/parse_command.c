/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:28:14 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/05 15:49:03 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parse_absolute_path2(char *str)
{
	int		i;
	char	**new_argv;

	i = 0;
	new_argv = NULL;
	new_argv = malloc(sizeof(char *) * 2);
	if (new_argv == NULL)
		return (NULL);
	i = (ft_strlen(str) - 1);
	while (str[i] != '/')
		i--;
	i++;
	new_argv[0] = NULL;
	new_argv[1] = NULL;
	new_argv[0] = ft_strdup(str + i);
	if (new_argv[0] == NULL)
		return (destroy_str(new_argv), NULL);
	return (new_argv);
}

int	parse_absolute_path(t_command *command)
{
	command->argv = parse_absolute_path2(command->name);
	if (command->argv == NULL)
		return (perror("Malloc Error\n"), 1);
	command->path = ft_strdup(command->name);
	if (command->path == NULL)
		return (perror("Malloc Error\n"), 1);
	if (access(command->path, F_OK) != 0)
		return (perror("Access failed \n"), 1);
	return (0);
}

int	parse_command(t_command *command, char **env)
{
	(void)env;
	if ((command->name[0] == '/') | (command->name[0] == '.'))
	{
		if (parse_absolute_path(command) == 1)
			return (1);
	}
	else
	{
		command->path = return_path(env);
		if (command->path == NULL)
			return (1);
		command->split_path = return_env(command->path);
		if (command->split_path == NULL)
			return (1);
		command->argv = ft_split(command->name, ' ');
		command->path = ft_check_path(command->split_path, command);
	}
	return (0);
}
