/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:43:44 by tnoulens          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/12 13:18:19 by cfontain         ###   ########.fr       */
=======
/*   Updated: 2022/09/08 14:22:00 by tnoulens         ###   ########.fr       */
>>>>>>> 028d83a75eff617d6a570501db96db6e715f6eeb
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *minishell)
{
<<<<<<< HEAD
	ft_lstclear(minishell->gb);
=======
	clean_up(cm->gb, cm->env);
>>>>>>> 028d83a75eff617d6a570501db96db6e715f6eeb
	printf("exit\n");
	exit(cm->exec_ret);
}
