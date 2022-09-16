/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:14:25 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/16 17:06:47 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd(t_minishell *ms, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	(void)ms;
	char *temp;
	temp = NULL;
	if (argc > 2)
		return (ft_printf("cd:too much arguments\n"), 1);
	if (chdir(argv[1]) == -1)
		return (ft_printf("%s", strerror(errno)), errno);
	return (0);
}