/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:23:14 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/17 00:04:08 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(int argc, char **argv)
{
	int		option_n;

	option_n = 0;
	while (--argc > 0 && (*++argv)[0] == '-')
	{
		if (*++argv[0] == 'n')
			option_n = 1;
		else if (argc == 1)
			printf("-%s", *argv);
		else
			printf("-%s ", *argv);
	}
	while (*argv && argc-- > 0)
	{
		if (argc > 0)
			printf("%s ", *argv);
		else
			printf("%s", *argv);
		argv++;
	}
	if (!option_n)
		printf("\n");
	return (SUCCESS);
}
/*
int main(int argc, char **argv)
{
	ft_echo(argc, argv);
	return 0;
}
*/
