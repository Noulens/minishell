/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:45:42 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/02 13:22:28 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **tofree)
{
	int	k;

	k = 0;
	if (!tofree)
		return ;
	if (!*tofree)
		return ;
	while (tofree[k])
		free(tofree[k++]);
	free(tofree);
}
