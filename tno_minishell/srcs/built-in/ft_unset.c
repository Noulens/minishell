/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:31:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/23 18:42:23 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_unset(char **envp, char **name)
{
	int		i;
	char	*p;

	i = 0;
	while (name[i])
	{
		p = getenv(name[i]);
	}
}
