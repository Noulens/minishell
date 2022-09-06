/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:33:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/06 17:14:35 by cfontain         ###   ########.fr       */
=======
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:33:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/06 14:13:00 by tnoulens         ###   ########.fr       */
>>>>>>> e3002d26c9fff1cd7daa32407f6478555edfbe72
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*g_cm;

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

int	space_only(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (ft_isspace(p[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char		*p;
	t_command	cm;

	init_struct(&cm, envp, argc, argv);
	g_cm = &cm;
	print_welcome_msg();
	signal_handling();
	while (42)
	{
		p = prompt_line(&cm);
		if (space_only(p))
		{
			cm.sigint = FALSE;
			continue ;
<<<<<<< HEAD

=======
		}
>>>>>>> e3002d26c9fff1cd7daa32407f6478555edfbe72
		cm.cmd = ft_split(p, '|');
		cm.gb = ft_lstnew(NULL, (void **)cm.cmd);
		if (cm.gb == NULL)
			return (ft_printf("%s", strerror(errno)), errno);
		cm.exec_ret = pipex(&cm);
		ft_lstclear(cm.gb);
		printf("%d\n", cm.exec_ret);
		init_struct(&cm, envp, argc, argv);
	}
	return (0);
}
