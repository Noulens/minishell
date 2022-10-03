/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:34:55 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/03 17:53:12 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_welcome_msg(void)
{
	char	*user;

	ft_printf(YELLOW"\n🅼 🅸 🅽 🅸 🆂 🅷 🅴 🅻 ->"BLINK_YELLOW"🅻\n"WHITE);
	user = getenv("USER");
	if (!user)
		ft_printf("\nWelcome,"RED" no env detected at launch"END);
	else
		ft_printf ("\nWelcome %s", user);
	ft_printf("\n"END);
}
