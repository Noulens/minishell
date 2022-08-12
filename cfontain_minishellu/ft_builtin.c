#include "minishell.h"

int	ft_cd(t_minishell *minishell)
{
	int	status;

	status = 0;
	char	*path;
	path = NULL;
	path = strdup(minishell->command.name + 3);
	if (path == NULL)
		return (perror("Malloc error"), 1);
	status = chdir(path);
	if (status == -1)
		perror("chdir");
	if (minishell->pathname)
		free (minishell->pathname);
	minishell->pathname = path;	
	return (0);
}

int ft_builtin(t_minishell *minishell, char **env)
{
	int status;
	
	status = 0;
	if (ft_strncmp(minishell->command.name, "cd", 2) == 0)
	{
		if (ft_cd(minishell) == 1)
			return (1);
		return (0);	
	}		
	if (ft_strncmp(minishell->command.name, "pwd", 3) == 0)
	{
		ft_printf("%s\n", minishell->pathname);
		return (0);	
	}
	if (ft_strncmp(minishell->command.name, "echo", 4) == 0)
	{

	}
	if (ft_strncmp(minishell->command.name, "export", 6) == 0)
	{

	}
	if (ft_strncmp(minishell->command.name, "unset", 5) == 0)
	{

	}
	if (ft_strncmp(minishell->command.name, "env", 3) == 0)
	{
		ft_printab(env);
		return (0);
	}
	if (ft_strncmp(minishell->command.name, "exit", 4) == 0)
	{
		exit(status);
	}	

	return (1);
}