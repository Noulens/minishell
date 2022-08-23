/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:47:10 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/23 16:48:12 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_pwd(void)
{
	char	wd[PATH_MAX];

	if (getcwd(wd, PATH_MAX))
	{
		ft_putendl_fd(wd, 1);
		return (SUCCESS);
	}
	else
		return (FAIL);
}
/*
int main(void)
{
	ft_pwd();
	return 0;
}
*/
