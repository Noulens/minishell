/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:34:55 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/02 22:14:48 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_welcome_msg(void)
{
	char	*user;

	ft_printf(YELLOW"\n🅼 🅸 🅽 🅸 🆂 🅷 🅴 🅻 ->"BLINK_YELLOW"🅻"WHITE);
	user = getenv("USER");
	if (!user)
		ft_printf("\nWelcome,"RED" no env detected at launch"END);
	else
		ft_printf ("\nWelcome %s", user);
	ft_printf("\n"END);
}
