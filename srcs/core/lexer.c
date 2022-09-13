
#include "minishell.h"

void	ft_lstclear_tok(t_tok *lst)
{
	t_tok	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		if (lst->data)
			free(lst->data);
		free(lst);
		lst = tmp;
	}
	lst = NULL;
}

void	printlist(t_tok *list)
{
	if (list)
	{
		while (list != NULL)
		{
			if (list->data != NULL)
				ft_printf("%s\n", list->data);
			ft_printf("%d\n", list->type);
			list = list->next;
		}
	}
}

t_tok	*ft_lstlast_tok(t_tok *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_tok(t_tok **lst, t_tok *new)
{
	t_tok	*pl;

	if (lst)
	{
		if (*lst)
		{
			pl = ft_lstlast_tok(*lst);
			pl->next = new;
		}
		else
			*lst = new;
	}
}

t_tok	*ft_lstnew_tok(char *content, int content2)
{
	t_tok	*first;

	first = (t_tok *)malloc(sizeof(t_tok));
	if (!first)
		return (NULL);
	first->data = content;
	first->type = content2;
	first->next = NULL;
	return (first);
}

int cmd_lexer(char *str, int i, t_minishell *minishell)
{
	char	c;
	char	*new_str;
	int		j;
	int		trigger;

	j = i;
	c = 0;
	trigger = 0;
	while (str[i] != 0 && char_is_token_with_trigg(str[i], trigger) == 0)
	{
		if (char_is_quote(str[i]) == 0 && check_quote(str, i) == 0)
		{
			trigger = 1;
			c = str[i];
			i++;
			continue;
		}
		if (c == str[i])
			trigger = 0;
		i++;
	}
	new_str = calloc(sizeof(char) , (i + 1));
	if (new_str == NULL)
		return (-1);
	ft_strlcpy(new_str, str + j, ((i - j) + 1));
	//ft_printf("%s\n", new_str);
	ft_lstadd_back_tok(&minishell->list, ft_lstnew_tok(new_str, 0));
	return (i);
}

int chevron(char *str, int i, t_minishell *minishell, int type)
{
	char	c;
	char	*new_str;
	int		j;

	j = i;
	i++;
	while (str[i] != 0 && char_is_whitespace(str[i]) == 1)
		i++;
	while (str[i] != 0 && char_is_whitespace(str[i]) == 0 && char_is_token(str[i]) == 0)
	{
		if (char_is_quote(str[i]) == 0 && check_quote(str, i) == 0)
		{
			c = str[i];
			i++;
			if (c == 34)
			{
				while(str[i] != 0 && str[i] != c && str[i] != '$')
					i++;
			}
			else
			{
				while(str[i] != 0 && str[i] != c)
				i++;
			}	
		}
		i++;
	}
	new_str = calloc(sizeof(char) , (i + 1));
	if (new_str == NULL)
		return (-1);
	ft_strlcpy(new_str, str + j, ((i - j) + 1));
	//ft_printf("%s\n", new_str);
	ft_lstadd_back_tok(&minishell->list, ft_lstnew_tok(new_str, type));
	return (i);
}

int chevron_lexer(char *str, int i, t_minishell *minishell)
{
	if (str[i] == '<')
		i  = chevron(str, i, minishell, 1);
	else if (str[i] == '>')
		i = chevron(str, i, minishell, 2);
	if (i == -1)
		return (-1);
	return (i);	
}

int	pipe_lexer(char *str, int i, t_minishell *minishell)
{
	char *new_str;

	(void)str;
	new_str = calloc(sizeof(char) , 2);
	if (new_str == NULL)
		return (-1);
	new_str[0] = '|';
	ft_lstadd_back_tok(&minishell->list, ft_lstnew_tok(new_str, 3));
	return ((i + 1));
}

/*int alias_lexer(char *str, int i, t_minishell *minishell)
{
	char	*new_str;
	int		j;

	j = i;
	i++;
	while (str[i] != 0 && char_is_whitespace(str[i]) == 0 && char_is_token(str[i]) == 0 && char_is_quote(str[i]) == 1)
		i++;
	new_str = calloc(sizeof(char) , (i + 1));
	if (new_str == NULL)
		return (-1);
	ft_strlcpy(new_str, str + j, ((i - j) + 1));
	//ft_printf("%s\n", new_str);
	ft_lstadd_back_tok(&minishell->list, ft_lstnew_tok(new_str, 4));
	return (i);
}*/

int lexer(char *str, t_minishell *minishell)
{
	int     i;
	char *end;

	end = NULL;
	(void)end;
	i = 0;
	while (str[i] != 0)
	{
		while (char_is_whitespace(str[i]) == 1)
			i++;
		if (str[i] == '>' || str[i] == '<')
			i = chevron_lexer(str, i, minishell);
		else if (str[i] == '|')
			i = pipe_lexer(str, i, minishell);
		else
			i = cmd_lexer(str, i, minishell);
		if (i == -1)
				return (1);	
	}
	return (0);	
}