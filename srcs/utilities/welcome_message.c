/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:34:55 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/02 14:16:31 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_welcome_msg(void)
{
	char	*username;

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
	username = getenv("USER");
	if (!username)
		ft_printf("\nWelcome, unknown env -i tester...");
	else
		ft_printf ("\nWelcome %s", username);
	ft_printf("\n"END);
}
/*
int main(void)
{
	print_welcome_msg();
	return 0;
}
*/
