/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:24:29 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/22 16:42:42 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	pid_t 	pid;
	int		end[2];
	char	msg[30];
	int		nb_char;
	char	buf[30];

	(void)argc;
	if (pipe(end) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		printf("Child : writing msg in pipe...\n");
		ft_strlcpy(msg, argv[1], 30);
		ft_putstr_fd(msg, end[1]);
		close(end[0]);
		close(end[1]);
		return (0);
	}
	else
	{
		waitpid(pid, NULL, 0);
		printf("Parent : msg incoming, decoding...\n");
		nb_char = read(end[0], buf, 30);
		close(end[0]);
		close(end[1]);
		if (nb_char == -1)
			return (1);
		buf[nb_char] = '\0';
		printf("Parent : msg is :\n%s\n", buf);
	}
	return 0;
}
