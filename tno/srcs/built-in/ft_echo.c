/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:23:14 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/28 21:35:39 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_minishell *minishell, int argc, char **argv)
{
	int		option_n;
	int		i;

	(void)minishell;
	option_n = 0;
	i = 1;
	while (--argc > 0 && argv[i][0] == '-')
	{
		if (argv[i][1] == 'n' && argv[i][2] == '\0')
			option_n = i++;
		else if (argc == 1)
			ft_printf("%s", argv[i++]);
		else
			ft_printf("%s ", argv[i++]);
	}
	while (argv[i] && argc-- > 0)
	{
		if (argc > 0)
			ft_printf("%s ", argv[i++]);
		else
			ft_printf("%s", argv[i++]);
	}
	if (!option_n)
		ft_printf("\n");
	return (SUCCESS);
}
