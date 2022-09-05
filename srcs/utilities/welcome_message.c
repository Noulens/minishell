/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:34:55 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/05 16:37:24 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
