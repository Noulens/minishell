/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:46:51 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/05 13:04:44 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!big || !little)
		return (NULL);
	if (little[0] == 0)
		return ((char *)big);
	while ((big[i] != 0 && i < len))
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(big + i, little, (ft_strlen(little))) == 0)
			{
				if (ft_strlen(little) > (len - i))
					break ;
				return ((char *) big + i);
			}	
		}
		i++;
	}
	return (NULL);
}

/*
int main()
{
	//char haystack[30] = "aaabcabcd";	
	//printf("%s", ft_strnstr(haystack, "", 8));
	//check(ft_strnstr(haystack, "cd", 8) == NULL);
	printf("%s", ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15));
}*/