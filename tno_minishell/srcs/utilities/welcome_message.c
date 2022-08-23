/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:34:55 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/23 16:47:41 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_welcome_msg(void)
{
	char	*username;

	printf("\n"WHITE);
	printf("░▒░    ░░▓  ░ ▒░     ▒▒░▓▒▒▓▒ ▒ ░ ▒ ░  ▒░░▒░░░▒░▓      ▒▓     \n");
	printf("███╗   ███╗██╗███╗   ██╗██╗██████╗██╗  ██╗█████╗██╗    ██╗    \n");
	printf(YELLOW);
	printf("████╗ ████║██║████╗  ██║██║██╔═══╝██║  ██║██╔══╝██║    ██║    \n");
	printf("██╔████╔██║██║██╔██╗ ██║██║██████╗███████║█████╗██║    ██║    \n");
	printf("██║╚██╔╝██║██║██║╚██╗██║██║╚═══██║██╔══██║██╔══╝██║    ██║    \n");
	printf("██║ ╚═╝ ██║██║██║ ╚████║██║██████║██║  ██║█████╗██████╗██████╗\n");
	printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═════╝╚═╝  ╚═╝╚════╝╚═════╝╚═════╝\n");
	username = getenv("USER");
	if (!username)
		printf("\nWelcome, unknown env -i tester...");
	else
		printf ("\nWelcome %s", username);
	printf("\n"END);
}
/*
int main(void)
{
	print_welcome_msg();
	return 0;
}
*/
