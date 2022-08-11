/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:04:37 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/13 15:44:01 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i] != 0)
	{
		(*f)(i, s + i);
		i++;
	}
}
/*
void
iter(unsigned int i, char * s) {
	*s += i;
}
	
int main()
{
	{
	char s[] = "";
	ft_striteri(s, iter);
	printf("%d\n", strcmp(s, ""));
	}
	
	{
	char s[] = "0";
		ft_striteri(s, iter);
		printf("%d\n", strcmp(s, "0"));
	}
	{
	char s[] = "0000000000";
		ft_striteri(s, iter);
		printf("%s\n", s);
		printf("%d\n", strcmp(s, "0123456789"));
		//  check(!strcmp(s, "0123456789"));		
	}	
}		*/