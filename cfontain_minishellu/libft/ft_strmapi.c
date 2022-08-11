/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:59:35 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/09 12:46:24 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char ) * (ft_strlen(s) + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	while (i <= ft_strlen(s))
	{
		str[i] = 0;
		i++;
	}
	i = 0;
	while (s[i] != 0)
	{
		str[i] = f(i, s[i]);
		i++;
	}	
	return (str);
}

/*
int	main()
{
	ft_strmapi("bonsoir", )
}*/