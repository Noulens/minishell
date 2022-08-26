/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:45:42 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/26 16:16:19 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **tofree)
{
	int	k;

	k = 0;
	if (!tofree && !*tofree)
		return ;
	while (tofree[k])
		free(tofree[k++]);
	free(tofree);
}
