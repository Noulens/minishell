/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:08:38 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/15 17:24:28 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strl(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

static int	ft_size(char **str, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			++j;
			++k;
		}
		++i;
	}
	return (k);
}

static void	ft_supercat(char *dest, char **str, char *sep, int size)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			dest[k++] = str[i][j++];
		}
		if (i < size - 1)
		{
			l = 0;
			while (sep[l])
			{
				dest[k++] = sep[l++];
			}
		}
		++i;
	}
	dest[k] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*sct;
	int		total;
	int		len_sep;

	if (size == 0 || !strs)
		return (NULL);
	total = ft_size(strs, size);
	len_sep = ft_strl(sep);
	sct = (char *)malloc(total + (size - 1) * len_sep + 1);
	if (!sct)
		return (NULL);
	ft_supercat(sct, strs, sep, size);
	return (sct);
}
