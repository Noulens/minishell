/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:09:29 by waxxy             #+#    #+#             */
/*   Updated: 2022/09/22 15:19:13 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*isallspace(char *str)
{
	char	*p;

	if (str == NULL)
		return (NULL);
	p = str;
	while (*p)
	{
		if (!ft_isspace(*p))
			return (p);
		p++;
	}
	return (NULL);
}

int	parse(t_minishell *ms)
{
	t_command	**pa;
	t_tok		*tmp;
	char		*cmdline;
	int			i;

	pa = malloc_pa(ms, &i, &tmp, &cmdline);
	if (pa == NULL)
		return (1);
	while (tmp)
	{
		if (tmp->type == 0 && ttok0(pa, &i, &cmdline) == 1)
			return (perror("parse"), free_param(pa), error_clean_up(ms), 1);
		else if (tmp->type == 1 && ttok1(tmp, pa, i) == 1)
			return (perror("parse"), free_param(pa), error_clean_up(ms), 1);
		else if (tmp->type == 2 && ttok2(tmp, pa, i) == 1)
			return (perror("parse"), free_param(pa), error_clean_up(ms), 1);
		else if (tmp->type == 4 && ttok4(tmp, pa, i) == 1)
			return (perror("parse"), free_param(pa), error_clean_up(ms), 1);
		else if (ttok356(tmp, pa, &i, &cmdline) == -1)
			return (free_param(pa), error_clean_up(ms), 1);
		tmp = tmp->next;
	}
	ms->cm = pa;
	return (0);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	ft_printf("res:%s\n", gethdname(argv[1]));
	return 0;
}*/
