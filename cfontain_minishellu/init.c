/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:12:34 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/05 12:02:42 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_command(t_command *command)
{
	
	command->name = NULL;
	command->argv = NULL;
	command->path = NULL;
	command->split_path = NULL;
}


void	init(t_minishell *minishell)
{
	init_command(&minishell->command);
	minishell->username = NULL;
	minishell->pathname = NULL;
}
