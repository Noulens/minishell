
#include "minishell.h"

void    init_username(t_minishell *minishell)
{
	//minishell->username = malloc(sizeof(char ) * 500);
	minishell->pathname = malloc(sizeof(char ) * 1024);
	minishell->username = getenv("USERNAME");
	getcwd(minishell->pathname, 1024);
	}