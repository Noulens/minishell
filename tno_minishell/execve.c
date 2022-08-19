/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:29:21 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/19 18:30:35 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*env_parser(char *env_var)
{
	char	*p;
	char	*env_ptr;

	p = NULL;
	env_ptr = getenv(env_var);
	if (!env_ptr)
		return (NULL);
	p = ft_substr(env_ptr, 0, ft_strlen(env_ptr));
		if (!p)
			return (write(1, "malloc issue env_parser\n", 24), NULL);
	return (p);
}

char	**paths_maker(void)
{
	char	*path;
	char	**bin_path;
	char	*tmp;
	char	**tmp2;
	int		i;

	path = env_parser("PATH");
	if (!path)
		bin_path = ft_split("/usr/bin", ' ');
	else
		bin_path = ft_split(path, ':');
	free(path);
	if (!bin_path)
		return (NULL);
	i = -1;
	while (bin_path[++i])
	{
		tmp = bin_path[i];
		tmp2 = bin_path;
		bin_path[i] = ft_strjoin(bin_path[i], "/");
		if (!bin_path[i])
			return (ft_free_split(tmp2), NULL);
		free(tmp);
	}
	return (bin_path);
}

char	*cmd_check(char **bin_path, char *cmd)
{
	char	*tmp;
	int		i;

	if (!bin_path || !*bin_path)
		return (NULL);
	i = -1;
	while (bin_path[++i])
	{
		tmp = ft_strjoin(bin_path[i], cmd);
		if (access(tmp, F_OK | X_OK) == 0)
			return (ft_free_split(bin_path), tmp);
		else
			free(tmp);
	}
	return (ft_free_split(bin_path), NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_path;

	if (argc > 1)
	{
		if (access(argv[1], F_OK | X_OK) == 0)
			cmd_path = argv[1];
		else
			cmd_path = cmd_check(paths_maker(), argv[1]);
		if (!cmd_path)
			return (-1);
		execve(cmd_path, ++argv, envp);
	}
	return (0);
}
