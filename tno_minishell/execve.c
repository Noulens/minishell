/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:29:21 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/18 15:41:17 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*env_parser(char **envp)
{
	char	*p;

	while (*envp)
	{
		p = ft_strnstr(*envp, "PATH=", 5);
		if (!p)
			++envp;
		else
		{
			p = ft_substr(p, 0, ft_strlen(p));
			if (!p)
				return (write(1, "malloc issue env_parser", 23), NULL);
			break ;
		}
	}
	return (p);
}

char	**paths_maker(char **envp)
{
	char	*path;
	char	**bin_paths;
	char	*tmp;
	int		i;

	path = env_parser(envp);
	if (!path)
		bin_paths = ft_split("/usr/bin", ' ');
	else
		bin_paths = ft_split(path + 5, ':');
	free(path);
	i = -1;
	while (bin_paths[++i])
	{
		tmp = bin_paths[i];
		bin_paths[i] = ft_strjoin(bin_paths[i], "/");
		free(tmp);
	}
	return (bin_paths);
}

char	*cmd_check(char **bin_paths, char *cmd)
{
	char	*tmp;
	int		i;
	
	i = -1;
	while (bin_paths[++i])
	{
		tmp = ft_strjoin(bin_paths[i], cmd);
		if (access(tmp, F_OK | X_OK) == 0)
			return (ft_free_split(bin_paths), tmp);
		else
			free(tmp);
	}
	return (write(1, "command not found", 17), NULL);
}

int	main(int argc, char **argv, char **envp)
{

	return (0);
}
