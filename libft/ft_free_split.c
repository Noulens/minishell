/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:45:42 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/13 14:34:53 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **tofree)
{
	int	k;

	k = -1;
	if (tofree == NULL)
		return ;
	if (*tofree == NULL)
		return ;
	while (tofree[++k])
	{
		free(tofree[k]);
		tofree[k] = NULL;
	}
	free(tofree);
	tofree = NULL;
}
