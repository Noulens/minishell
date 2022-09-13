/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:42:15 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/13 20:21:41 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void exportlist(t_list *list)
{
	if (list)
	{
		while (list != NULL)
		{
			if (list->content != NULL)
            {
				ft_printf("declare -x ");
                ft_printf("%s\n", list->content);
            }
			list = list->next;
		}
	}
}

int ft_export(t_minishell *minishell, int argc, char **argv)
{
    int i;
    
    if (argc == 1)
        exportlist(minishell->env);
    else
    {
        i = 1;
        while (i < argc)
        {
            ft_lstadd_back(&minishell->env, ft_lstnew(ft_strdup(argv[i]), NULL));
            if (ft_lstlast(minishell->env)->content == NULL)
				return(perror("ft_export"), errno);
            ++i;
        }
        if (minishell->env_array != NULL)
            free(minishell->env_array);
        list_to_array(minishell->env);
    }
}
