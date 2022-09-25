/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:31:54 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/25 13:26:15 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int	builtin_mgmt(t_command *cm, int i, int cmd_nbr, t_minishell *ms)
{
	int			i;
	int			nbr_builtin;
	t_builtin	*p;
	int			k;

	k = nb_cmd()
	i = 0;
	p = (t_builtin *)ms->bi;
	nbr_builtin = 7;
	while (i < nbr_builtin)
	{
		if (ft_strncmp(argv[0], p[i].name, 10))
		{
			ms->exec_ret = p[i].func(ms, argc, argv);
			return (1);
		}
		i++;
	}
	return (0);;
}*/
/*
int	child_mgmt(int i, int cmd_nbr, t_minishell *ms)
{
	char	**arg_cm;

	ms->pids[i] = fork();
	if (ms->pids[i] == -1)
		return (perror("child_mgmt"), errno);
	else if (!ms->pids[i])
	{
		if (i == 0 && cmd_nbr == 1)
			dupper(cm->fd[0], cm->fd[1]);
		else if (i == 0)
			dupper(cm->fd[0], cm->end[1]);
		else if (i == cmd_nbr - 1)
			dupper(cm->end[2 * i - 2], cm->fd[1]);
		else
			dupper(cm->end[2 * i - 2], cm->end[2 * i + 1]);
		close_pipes(cmd_nbr, cm->end, cm);
		arg_cm = cm->cmd;
		if (gb_c(&ms->gb, NULL, (void **)arg_cm) == -1)
			return (ft_lstclear(ms->gb), exit(errno), errno);
		cm->exec_ret = exec(ms, arg_cm, cm->env);
		close_std_in_child();
		clean_up(ms->gb, ms->env_array, ms->env);
		exit(cm->exec_ret);
	}
	return (0);
}*/

void	get_fd_in(t_command *cm)
{
	if (cm->here_doc >= TRUE)
	{
		cm->fd[0] = open(".here_doc.tmp", O_RDONLY);
		if (cm->fd[0] == -1)
			perror("get_fd_in");
	}
}

int	malloc_pids(t_minishell *ms)
{
	ms->pids = (pid_t *)malloc(ms->nbr_cmd * sizeof(pid_t));
	if (gb_c(&ms->gb, (void *)ms->pids, NULL) == -1)
		return (perror("pipex pids"), errno);
	ms->end = malloc(2 * sizeof(int) * (ms->nbr_cmd - 1) + 2 * sizeof(int));
	if ((gb_c(&ms->gb, (void *)ms->end, NULL) == -1 && ms->nbr_cmd - 1 != 0)
		|| open_pipes(ms->nbr_cmd, ms->end) != 0)
		return (perror("pipex end"), errno);
	return (0);
}

int	pipex(t_minishell *ms)
{
	int		ret;
	int		i;

	//get_fd_in(cm); /* a mettre dans le child, le dernier fdin a etre trouver est le fd in*/
	if (malloc_pids(ms) != 0)
		return (error_clean_up(ms), -1);
	i = -1;
	//while (++i < ms->nbr_cmd && ms->sigint == FALSE)
	//	child_mgmt(i, ms->nbr_cmd, ms);
	//close_pipes(ms->nbr_cmd, ms->end, cm); // faire un while pour fermer tous les fd de ms->cm
	i = -1;
	while (++i < ms->nbr_cmd && ms->sigint == FALSE)
	{
		waitpid(ms->pids[i], &ret, 0);
		if (WIFEXITED(ret))
			printf("P %d, exit ok: %d\n", i, ms->exec_ret = WEXITSTATUS(ret)); // printf a enlever apres les tests
		else
		{
			ms->exec_ret = errno;
			printf("P %d, interrupted\n", i); // printf a enlever apres les tests
		}
	}
	return (ms->exec_ret);
}
