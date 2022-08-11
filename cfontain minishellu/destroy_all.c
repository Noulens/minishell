/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:26:10 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/05 12:04:16 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_command(t_command *command)
{
	
	if (command->name)
		free (command->name);
	if (command->argv != NULL)
		destroy_str(command->argv);
	if (command->path != NULL)
		free (command->path);
	if (command->split_path != NULL)
		destroy_str(command->split_path);
}


void destroy_all(t_minishell *minishell)
{
	//if (minishell->command != NULL)
	//	free (minishell->command );
	destroy_command(&minishell->command);
	if (minishell->username)
		free (minishell->username);
	if (minishell->pathname)
		free (minishell->pathname);
}