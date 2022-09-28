/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:14:25 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/28 18:45:17 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*gethome(t_minishell *ms)
{
	char	**p;
	int		i;

	p = ms->env_array;
	i = 0;
	if (p != NULL)
	{
		while (p[i] != NULL)
		{
			if (!ft_strncmp(p[i], "HOME=", 5))
				return (p[i] + 5);
			++i;
		}
	}
	return (NULL);
}

int	ft_cd(t_minishell *ms, int argc, char **argv)
{
	char	*p;

	(void)argc;
	(void)argv;
	if (argc > 2)
		return (ft_putendl_fd("cd:wrong arguments", 2), 1);
	if (argc == 1)
		{
			p = gethome(ms);
			if (p == NULL)
				return (ft_putendl_fd("HOME not set", 2), 1);
			if (chdir(p) == -1)
				return (perror("cd gethome"), errno);				
		}
	else if (chdir(argv[1]) == -1)
		return (perror("cd chdir"), errno);
	return (0);
}
