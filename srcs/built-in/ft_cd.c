/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:14:25 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/26 13:45:13 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_minishell *ms, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	(void)ms;
	if (argc > 2)
		return (ft_printf("cd:too much arguments\n"), 1);
	if (chdir(argv[1]) == -1)
		return (ft_printf("%s", strerror(errno)), errno);
	return (0);
}
