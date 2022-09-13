
#include "minishell.h"

char *parse_without_quote(char *str)
{
	char *new_str;
	int		i;
	int		j;
	char	c;
	int		trigger;

	trigger = 0;
	c = 0;
	j = 0;
	i = 0;
	new_str = calloc(sizeof(char), (ft_strlen(str) + 1));
	while (str[i] != 0)
	{
		if (char_is_quote(str[i]) == 0 && check_quote(str, i) == 0 && trigger == 0)
		{
			c = str[i];
			trigger++;
			i++;
		}
		if (str[i] == c)
		{
			i++;
			trigger = 0;
			continue ;
		}	
		new_str[j] = str[i];
		j++;
		i++;
	}
	return (new_str);
}


int parse_lexer(t_minishell *minishell, char **env)
{
	char *str;
	char *str2;
	t_tok *temp;
	temp = minishell->list;
	while (minishell->list)
	{
		str = expend_alias(minishell->list->data, env, minishell);
		free (minishell->list->data);
		str2 = parse_without_quote(str);
		free (str);
		minishell->list->data = str2;
		minishell->list = minishell->list->next;
	}
	minishell->list = temp;
	ft_lstadd_back_tok(&minishell->list, ft_lstnew_tok(NULL, 4));
	return (0);
}