#include "minishell.h"

int cmd_argv(char **argv, t_minishell *minishell)
{
	char *p;

	if (ft_strncmp(argv[0], "-c", 2) == 0)
		p = argv[1];
	else
		p = str_join_tab(argv);
	if (p == NULL)
		return (1);
	if (lexer_and_expend(p, minishell) == 1)
		return (ft_printf("%s", strerror(errno)), errno);
	if (parse(minishell) == 1)
		return (ft_printf("%s", strerror(errno)), errno);	
	ft_lstclear(minishell->gb);
	ft_lstclear_tok(minishell->list);
	printf("exit code: %d\n", minishell->exec_ret);
	free_param(minishell->cm);
	return (0);
}