/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:34:55 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/25 13:39:47 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_welcome_msg(void)
{
	char	*user;

	ft_printf("\n"WHITE);
	ft_printf("░▒░    ░░▓  ░ ▒░     ▒▒░▓▒▒▓▒ ▒ ░ ▒ ░  ▒░░▒░░░▒░▓     ▒▓    ");
	ft_printf("\n");
	ft_printf("███╗   ███╗██╗███╗   ██╗██╗██████╗██╗  ██╗█████╗██╗   ██╗   ");
	ft_printf("\n"YELLOW);
	ft_printf("████╗ ████║██║████╗  ██║██║██╔═══╝██║  ██║██╔══╝██║   ██║   ");
	ft_printf("\n");
	ft_printf("██╔████╔██║██║██╔██╗ ██║██║██████╗███████║█████╗██║   ██║   ");
	ft_printf("\n");
	ft_printf("██║╚██╔╝██║██║██║╚██╗██║██║╚═══██║██╔══██║██╔══╝██║   ██║   ");
	ft_printf("\n");
	ft_printf("██║ ╚═╝ ██║██║██║ ╚████║██║██████║██║  ██║█████╗█████╗█████╗");
	ft_printf("\n");
	ft_printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═════╝╚═╝  ╚═╝╚════╝╚════╝╚════╝");
	ft_printf("\n");
	user = getenv("USER");
	if (!user)
		ft_printf("\nWelcome, unknown env -i tester...");
	else
		ft_printf ("\nWelcome %s", user);
	ft_printf("\n"END);
}
/*
int main(void)
{
	print_welcome_msg();
	return 0;
}
*/
