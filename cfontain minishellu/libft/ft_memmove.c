/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:35:57 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/11 09:54:12 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest1;
	char		*src1;
	size_t		i;

	i = 0;
	dest1 = (char *)dest;
	src1 = (char *)src;
	if (dest1 > src1)
	{
		while (n-- > 0)
		{
			dest1[n] = src1[n];
		}
	}
	else
	{
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	return (dest1);
}
/*
int main()
{
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult1[] = {67, 68, 67, 68, 69, 0, 45};
	ft_memmove(sResult + 1, sResult, 2);
	printf("ma fonction\n%s\n", sResult);
	memmove(sResult1 + 1, sResult1, 2);
	printf("vrai fonction\n%s\n", sResult1);


}*/